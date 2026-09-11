#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

int toMinutes(string s) {
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

string format(int minutes) {
    string hh = to_string(minutes/60);
    if (hh.length() == 1) hh = "0" + hh;
    string mm = to_string(minutes%60);
    if (mm.length() == 1) mm = "0" + mm;
    return hh + ":" + mm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    int START_TIME = toMinutes("9:00");
    
    sort(timetable.begin(), timetable.end());
    vector<vector<int>> passengers(n); // [n번째 버스][도착 시간 (분)]
    
    int idx = 0;
    for (string time : timetable) {
        int minutes = toMinutes(time);
        if (passengers[idx].size() >= m) idx++;
        while(minutes > START_TIME + idx * t) idx++; 
        if (idx >= n) break;
        passengers[idx].push_back(toMinutes(time));
    }
    // 마지막 버스 마지막에 탑승
    if (passengers[n-1].size() < m) return format(START_TIME + (n-1) * t);
    return format(passengers[n-1][passengers[n-1].size()-1]-1);
}