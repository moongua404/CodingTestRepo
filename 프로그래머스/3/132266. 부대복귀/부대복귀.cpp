/*
일일이 탐색하는건 비싸니까 destination에서 한 번 탐색하자. 
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    unordered_map<int, vector<int>> paths;
    for (int i = 1; i <= n; i++) {
        paths.insert({i, {}});
    }
    
    for (vector<int> road : roads) {
        paths[road[0]].push_back(road[1]);
        paths[road[1]].push_back(road[0]);
    }
    
    vector<int> costs(n+1);
    for (int& c : costs) {
        c = -1;
    }
    
    queue<pair<int, int>> q; // {위치, 가격}
    q.push({destination, 0});
    costs[destination] = 0;
    while(!q.empty()) {
        pair<int, int> node = q.front();
        q.pop();
        for (int next : paths[node.first]) {
            if (costs[next] != -1) continue;
            costs[next] = node.second + 1;
            q.push({next, node.second+1});
        }
    }
    
    vector<int> answer(sources.size());
    for (int i = 0; i < sources.size(); i++) {
        answer[i] = costs[sources[i]];
    }
    return answer;
}