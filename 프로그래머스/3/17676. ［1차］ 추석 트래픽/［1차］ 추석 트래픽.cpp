/*
날짜는 고정 -> 시간 분 초 밀리초
max < 24 * 60 * 60 * 60 * 1000 = 216 * 24 * 1M ~= 6b

brute force
*/

#include <string>
#include <vector>
#include <utility>

using namespace std;

long getTime(string line) {
    long h  = stoi(line.substr(11, 2));
    long m  = stoi(line.substr(14, 2));
    long s  = stoi(line.substr(17, 2));
    long ms = stoi(line.substr(20, 3));
    return ms + 1000 * (s + 60 * (m + 60 * h));
}

long getDuration(string line) {
    long dms = stoi(line.substr(24, 1)) * 1000;
    if (line.length() > 26) {
        dms += stoi(line.substr(26, line.length() - 2));
    }
    return dms;
}

int solution(vector<string> lines) {
    int size = lines.size();
    pair<long, long>* time = new pair<long, long>[size]; //시작ms, 종료ms
    
    for (int i = 0; i < size; i++) {
        time[i].second = getTime(lines[i]);
        time[i].first = time[i].second - getDuration(lines[i]) + 1;
    }
    
    int max = 0;
    for (int i = 0; i < size; i++) {
        int cnt = 0;
        long rs = time[i].second, re = time[i].second + 1000;
        for (int j = 0; j < size; j++) {
            // 선분이력...
            // 끝점이 사이에 끼거나 시작점이 사이에 끼거나 중간에 위치할 때
            // ts rs te re || rs ts re te || rs ts te re
            long ts = time[j].first, te = time[j].second;
            if ((ts <= rs && te < rs) || (re <= ts && re < te)) {
                continue;
            }
            cnt++;
        }
        if (max < cnt) max = cnt;
    }
    
    return max;
}