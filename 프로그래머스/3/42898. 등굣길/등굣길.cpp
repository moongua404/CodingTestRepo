#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // {거리, 경우의 수}, 오버플로우 조심
    vector<vector<pair<int, int>>> board(n, vector<pair<int, int>>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            board[i][j] = {0x7FFFFFFF, 0};
        }
    }
    vector<vector<int>> blocked(n, vector<int>(m));
    for (vector<int>& puddle : puddles) {
        blocked[puddle[1]-1][puddle[0]-1] = true;
    }
    
    queue<pair<int, int>> q;
    q.push({0, 0});
    board[0][0] = {0, 1};
    while(!q.empty()) {
        pair<int, int> pos = q.front();
        q.pop();
        for (pair<int, int> dir : dirs) {
            int newF = pos.first + dir.first;
            int newS = pos.second + dir.second;
            if (newF < 0 || newF >= n || newS < 0 || newS >= m) continue;
            if (blocked[newF][newS]) continue;
            if (board[newF][newS].first==board[pos.first][pos.second].first+1) {
                // 큐이기에 지연되서 전파될 걱정은 할 필요 없음
                board[newF][newS].second += board[pos.first][pos.second].second;
                board[newF][newS].second %= 1000000007;
            }
            if (board[newF][newS].first > board[pos.first][pos.second].first+1) {
                board[newF][newS].first = board[pos.first][pos.second].first+1;
                board[newF][newS].second = board[pos.first][pos.second].second;
                q.push({newF, newS});
            }
        }
    }
    
    return board[n-1][m-1].second;
}