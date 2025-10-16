#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int connectedCount(map<int, vector<int>> nodes, int start, int exclude);

int solution(int n, vector<vector<int>> wires) {
    int min = n*n;
    
    map<int, vector<int>> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.insert({i, vector<int>()});
    }
    
    for (vector<int> wire : wires) {
        nodes[wire[0]].push_back(wire[1]);
        nodes[wire[1]].push_back(wire[0]);
    }
    
    for (vector<int> wire : wires) {
        int v = connectedCount(nodes, wire[0], wire[1]) - connectedCount(nodes, wire[1], wire[0]);
        if (v < 0) { v = -v; }
        if (v < min) { min = v; }
    }
    
    return min;
}

int connectedCount(map<int, vector<int>> nodes, int start, int exclude) {
    set<int> visited;
    queue<int> nexts;
    visited.insert(start);
    visited.insert(exclude);
    nexts.push(start);
    int count = 0;
    while(!nexts.empty()) {
        int next = nexts.front();
        visited.insert(next);
        nexts.pop();
        count++;
        vector<int> nextCandidates = nodes[next];
        for (int nextCandidate : nextCandidates) {
            if (visited.find(nextCandidate) == visited.end()) {
                nexts.push(nextCandidate);
            }
        }
    }
    return count;
}
