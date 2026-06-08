/*
BFS보다 먼 DP보다는 가까운
*/

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

bool inRange(pair<int, int> p, int s) {
    return (p.first >= 0 && p.first < s && p.second >= 0 && p.second < s);
}

int solution(vector<vector<int>> board) {
    int MAX_COST = 500 * 25 * 25 + 1;
    int size = board.size();
    
    vector<pair<int, pair<int, int>>> dirs = {
        {0, {-1, 0}}, {1, {1, 0}}, {2, {0, -1}}, {3, {0, 1}}
    }; // UDLR
    vector<vector<vector<int>>> costs(
        size, vector<vector<int>>(size, vector<int>(4)));
    for (vector<vector<int>>& o1 : costs) {
        for (vector<int>& o2 : o1) {
            for (int& o3 : o2) {
                o3 = MAX_COST;
            }
        }
    }
    
    for (int i = 0; i < 4; i++) {
        costs[0][0][i] = 0;
    }
    queue<pair<int, pair<int, int>>> pos;
    pos.push({1, {0, 0}});
    pos.push({3, {0, 0}});
    
    int loggingTag = 0;
    while(!pos.empty()) {
        loggingTag++;
        pair<int, pair<int, int>> node = pos.front();
        pos.pop();
        int baseCost = costs[node.second.first][node.second.second][node.first];
        for (pair<int, pair<int, int>> destDir : dirs) {
            int destF = node.second.first + destDir.second.first;
            int destS = node.second.second + destDir.second.second;
            if ((!inRange({destF, destS}, size)) || board[destF][destS] == 1) {
                continue;
            }
            int newCost = baseCost + 600;
            if (node.first == destDir.first) newCost -= 500;
            if (costs[destF][destS][destDir.first] > newCost) {
                costs[destF][destS][destDir.first] = newCost;
                pos.push({destDir.first, {destF, destS}});
            }
        }
    }
    
    int minV = 0x7FFFFFFF;
    for (int i = 0; i < 4; i++) {
        if (costs[size-1][size-1][i] < minV) minV = costs[size-1][size-1][i];
    }
    return minV;
}