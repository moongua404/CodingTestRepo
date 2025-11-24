#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

void solution() {
    int N;
    cin >> N;

    map<int, vector<int>> nodes;
    for (int i = 0; i < N; i++) {
        nodes.insert({i+1, {}});
    }
    for (int i = 0; i < N-1; i++) {
        int v1, v2;
        cin >> v1 >> v2;
        nodes[v1].push_back(v2);
        nodes[v2].push_back(v1);
    }

    vector<int> parentOf(N+1);
    set<int> visited;
    parentOf[1] = 0;
    queue<int> q;

    visited.insert(1);
    q.push(1);
    
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        vector<int> others = nodes[cur];
        for (int other : others) {
            if (visited.find(other) == visited.end()) {
                visited.insert(other);
                q.push(other);
                parentOf[other] = cur;
            }
        }
    }

    for (int i = 2; i < N+1; i++) {
        cout << parentOf[i] << "\n";
    }
}

int main() {
    solution();

    return 0;
}