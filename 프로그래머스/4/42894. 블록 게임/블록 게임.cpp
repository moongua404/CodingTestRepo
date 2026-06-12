/*
충전재를 위에서만 꽉 채움
왼쪽위에서부터 블록을 발견할 때까지 순회하며
발견하면 지울 수 있는지 확인 - 지울 수 있으면 지우고 충전재를 채우고 살짝 돌아감

50 * 50 * 200 = 5M
*/

#include <string>
#include <vector>

using namespace std;

bool isDestroyable(vector<vector<int>>& board,int v,int y,int x,int h,int w) {
    for (int i = y; i < y+h; i++) {
        for (int j = x; j < x+w; j++) {
            if (board[i][j] != -1 && board[i][j] != v) {
                return false;
            }
        }
    }
    return true;
}

void destroy(vector<vector<int>>& board, int v, int y, int x, int h, int w) {
    for (int j = x; j < x+w; j++) {
        for (int i = y; i < board.size(); i++) {
            if (board[i][j] == v) board[i][j] = 0;
            else if (board[i][j] != -1) break;
        }
    }
}

// y x h w
vector<int> getBlock(vector<vector<int>>& board, int v, int y, int x) {
    vector<pair<int, int>> pos; // {y, x}
    // 그냥 러프하게 주변 다 훑어버려
    for (int i = y-2; i <= y+2; i++) {
        if (i < 0 || i >= board.size()) continue;
        for (int j = x-2; j <= x+2; j++) {
            if (j < 0 || j >= board.size()) continue;
            if (board[i][j] == v) pos.push_back({i, j});
        }
    }
    int minX = 0x7FFFFFFF, minY = 0x7FFFFFFF, maxX = -1, maxY = -1;
    for (pair<int, int> p : pos) {
        if (p.first < minY) minY = p.first;
        if (p.first > maxY) maxY = p.first;
        if (p.second < minX) minX = p.second;
        if (p.second > maxX) maxX = p.second;
    }
    
    return {minY, minX, maxY-minY+1, maxX-minX+1};
}

void rain(vector<vector<int>>& board, int x, int w) {
    for (int j = x; j < x + w; j++) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][j] == 0) board[i][j] = -1;
            else if (board[i][j] != -1) break;
        }
    }
}

int solution(vector<vector<int>> board) {
    for (int j = 0; j < board.size(); j++) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][j] == 0) board[i][j] = -1;
            else break;
        }
    }
    
    int cnt = 0;
    for (int j = 0; j < board.size(); j++) {
        for (int i = 0; i < board.size(); i++) {
            if (board[i][j] == -1) continue;
            vector<int> b = getBlock(board, board[i][j], i, j);
            if (isDestroyable(board, board[i][j], b[0], b[1], b[2], b[3])) {
                destroy(board, board[i][j], b[0], b[1], b[2], b[3]);
                rain(board, b[1], b[3]);
                cnt++;
                j -= 6;
                if (j < 0) j = -1;
            }
            break;
        }
    }
    return cnt;
}