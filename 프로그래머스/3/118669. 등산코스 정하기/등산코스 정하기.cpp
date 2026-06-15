/*
루트를 기준으로 갈 수 있는 곳들을 들리며
    - 줄 때는 가중치를 더해서 전달
    - 받을때는 최소만 취사 선택
시작점 중 최소 가격을 선택
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    unordered_set<int> summitSet;
    for (int v : summits) {
        summitSet.insert(v);
    }
    vector<vector<pair<int, int>>> nodes(n+1); // [node]에서 갈 수 있는 {노드,가격}들
    for (vector<int> path : paths) {
        nodes[path[0]].push_back({path[1], path[2]});
        nodes[path[1]].push_back({path[0], path[2]});
    }
    
    vector<int> costs(n+1, 0x7FFFFFFF);
    
    vector<int> vec;
    for (int v : gates) {
        vec.push_back(v);
        costs[v] = 0;
    }
    while(!vec.empty()) {
        int v = vec.back();
        vec.pop_back();
        for (pair<int, int> next : nodes[v]) {
            int nextCost = max(costs[v], next.second);
            if (nextCost < costs[next.first]) {
                costs[next.first] = nextCost;
                if (summitSet.find(next.first) == summitSet.end()) {
                    vec.push_back(next.first);
                }
            }
        }
    }
    
    int bestV, bestCost = 0x7FFFFFFF;
    sort(summits.begin(), summits.end());
    for (int v : summits) {
        if (costs[v] < bestCost) {
            bestV = v;
            bestCost = costs[v];
        }
    }
    return {bestV, bestCost};
}