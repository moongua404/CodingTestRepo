/*
단순 구현? - 어차피 full scan 해야함
schedules의 단위를 분으로 바꾼 후 10을 더함 - threshold

모든 직원에 대해
    주말이 아닌 날에 대해
        threshold를 넘는게 하나도 없다면
            삼품을 받음
*/
#include <string>
#include <vector>

using namespace std;

int parseMinute(int hhmm) {
    return (hhmm / 100 * 60)
        + hhmm % 100;
}

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int REST_TIME = 10; // 10분의 여유 시간
    
    // 출근일 계산
    vector<int> days;
    for (int i = 0; i < 7; i++) { // 일주일 간
        startday %= 7;
        if (startday != 6 && startday != 0) {
            days.push_back(i);
        }
        startday++;
    }
    
    // 메인 로직
    int c = 0;
    
    for (int empIdx = 0; empIdx < timelogs.size(); empIdx++) {
        int suc = true;
        for (int day : days) {
            int goalTime = parseMinute(schedules[empIdx]) + REST_TIME;
            int empTime = parseMinute(timelogs[empIdx][day]);
            if (goalTime >= empTime) {
                continue;
            }
            suc = false;
            break;
        }
        if (suc) {
            c++;
        }
    }
    
    return c;
}