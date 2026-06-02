/*
그래프 탐색
백트래킹?
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<string> search(
    unordered_map<string, vector<pair<string, bool>>>& paths,
    vector<string>& history,
    int goal) {
    if (history.size() >= goal) return history;
    if (paths.find(history.back()) == paths.end()) return {};
    for (int i = 0; i < paths[history.back()].size(); i++) {
        if (!paths[history.back()][i].second) continue;
        paths[history.back()][i].second = false;
        history.push_back(paths[history.back()][i].first);
        vector<string> res = search(paths, history, goal);
        if (!res.empty()) return res;
        history.pop_back();
        paths[history.back()][i].second = true;
    }
    
    return {};
}

vector<string> solution(vector<vector<string>> tickets) {
    // [출발지][{도착지 - free} 들]
    unordered_map<string, vector<pair<string, bool>>> paths;
    for (vector<string> ticket : tickets) {
        if (paths.find(ticket[0]) == paths.end()) {
            paths.insert({ticket[0], {}});
        }
        paths[ticket[0]].push_back({ticket[1], true});
    }
    for (pair<const string, vector<pair<string, bool>>>& path : paths) {
        sort(path.second.begin(), path.second.end(),
             [](pair<string, bool> a, pair<string, bool> b) {
                 return a.first < b.first;
             });
    }
    
    vector<string> history{"ICN"};
    return search(paths, history, tickets.size() + 1);
}