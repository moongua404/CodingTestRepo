#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int v, i, j;
    Node(int v, int i, int j) : v(v), i(i), j(j) { }
    bool operator<(Node o) const {
        if (this->v == o.v) {
            if (this->i == o.v) return this->j < o.j;
            return this->i < o.i;
        }
        return this->v < o.v;
    }
};

bool inRange(int size, pair<int, int> pos) {
    return pos.first >= 0 && pos.first < size
            && pos.second >= 0 && pos.second < size;
}

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    vector<vector<int>> nums(N, vector<int>(N));
    vector<Node> nodes;
    nodes.reserve(N * N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> nums[i][j];
            nodes.push_back(Node(nums[i][j], i, j));
        }
    }
    sort(nodes.begin(), nodes.end());

    vector<vector<int>> dp(N, vector<int>(N, 1));
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (Node n : nodes) {
        for (pair<int, int> dir : dirs) {
            pair<int, int> adj = {n.i+dir.first, n.j+dir.second};
            if (!inRange(N, adj)) continue;
            if (nums[adj.first][adj.second] <= nums[n.i][n.j]) continue;
            if (dp[adj.first][adj.second] > dp[n.i][n.j]) continue;
            dp[adj.first][adj.second] = dp[n.i][n.j]+1;
        }
    }

    int best = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (dp[i][j] > best) best = dp[i][j];
        }
    }
    cout << best;

    return 0;
}