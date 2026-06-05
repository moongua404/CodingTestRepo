/*
DP -> 재귀
트리로 만든 후 리프부터, 자신과 자식들의 최소를 계산
한 점에 대해 이게 꺼졌을 때와 켜졌을 때 중 최소
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

unordered_map<int, unordered_set<int>> getAdj(
    vector<vector<int>>& lighthouse) {
    unordered_map<int, unordered_set<int>> adj;
    for (vector<int> path : lighthouse) {
        adj[path[0]].insert(path[1]);
        adj[path[1]].insert(path[0]);
    }
    return adj;
}

unordered_map<int, unordered_set<int>> toplikesort(
    int n, int start, unordered_map<int, unordered_set<int>>& adj) {
    vector<bool> visited(n+1);
    unordered_map<int, unordered_set<int>> filtered;
    for (int i = 1; i <= n; i++) {
        filtered[i] = {};
    }
    
    vector<int> vec;
    vec.push_back(start);
    visited[start] = true;
    while(!vec.empty()) {
        int node = vec.back();
        vec.pop_back();
        for (int v : adj[node]) {
            if (visited[v]) continue;
            visited[v] = true;
            filtered[node].insert(v);
            vec.push_back(v);
        }
    }
    return filtered;
}

pair<int, int> recur(int pivot, unordered_map<int, unordered_set<int>>& tree) {
    pair<int, int> minCost = {1, 0}; // 지금걸 켰을 때, 껐을 때
    for (int v : tree[pivot]) {
        pair<int, int> res = recur(v, tree);
        minCost.first += (res.first < res.second) ? res.first : res.second;
        minCost.second += res.first;
    }
    
    return minCost;
}

int solution(int n, vector<vector<int>> lighthouse) {
    unordered_map<int, unordered_set<int>> adj = getAdj(lighthouse);
    unordered_map<int, unordered_set<int>> sorted = toplikesort(n, 1, adj);
    pair<int, int> res = recur(1, sorted);
    
    return (res.first < res.second) ? res.first : res.second;
}