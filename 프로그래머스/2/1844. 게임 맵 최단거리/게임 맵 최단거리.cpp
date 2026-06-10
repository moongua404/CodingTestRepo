#include<vector>
#include<queue>
using namespace std;

int solution(vector<vector<int>> maps)
{
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    int h = maps.size(), w = maps[0].size();
    vector<vector<int>> board(h, vector<int>(w));
    for (vector<int>& line : board) {
        for (int& spot : line) spot = 0x7FFFFFFF;
    }
    
    queue<pair<int, int>> vec;
    vec.push({0, 0});
    board[0][0] = 1;
    while(!vec.empty()) {
        pair<int, int> pos = vec.front();
        vec.pop();
        for (pair<int, int> dir : dirs) {
            int newF = pos.first + dir.first;
            int newS = pos.second + dir.second;
            if (newF < 0 || newF >= h || newS < 0 || newS >= w) continue;
            if (maps[newF][newS] == 0) continue;
            if (board[newF][newS] <= board[pos.first][pos.second]+1) continue;
            board[newF][newS] = board[pos.first][pos.second]+1;
            vec.push({newF, newS});
        }
    }
    
    int res = board[h-1][w-1];
    if (res == 0x7FFFFFFF) return -1;
    return res;
}