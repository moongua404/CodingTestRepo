/*
슬라이딩 윈도우 + DP
O(m * n) // 맵 전체 순회 + width/height 순회
*/

#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<vector<int>> board(m+1, vector<int>(n+1, 0x7FFFFFFF));
    for (int i = 0; i < drops.size(); i++) {
        board[drops[i][0]+1][drops[i][1]+1] = i+1;
    }
    
    vector<vector<int>> compWidth(m+1, vector<int>(n-w+1));
    for (int i = 0; i < m+1; i++) {
        deque<int> deq;
        for (int j = 1; j < w+1; j++) {
            while (!deq.empty() && board[i][j] <= deq.back()) deq.pop_back();
            deq.push_back(board[i][j]);
        }
        for (int j = 0; j < n-w+1; j++) {
            while (!deq.empty() && board[i][j] == deq[0]) deq.pop_front();
            while (!deq.empty() && board[i][j+w] <= deq.back()) deq.pop_back();
            deq.push_back(board[i][j+w]);
            compWidth[i][j] = deq[0];
        }
    }
    
    pair<int, int> pos;
    int best = -1;
    for (int j = 0; j < n-w+1; j++) {
        deque<int> deq;
        for (int i = 0; i < h; i++) {
            while (!deq.empty() && compWidth[i][j] <= deq.back()) deq.pop_back();
            deq.push_back(compWidth[i][j]);
        }
        for (int i = 0; i < m-h+1; i++) {
            while (!deq.empty() && compWidth[i][j] == deq[0]) deq.pop_front();
            while (!deq.empty() && compWidth[i+h][j] <= deq.back()) deq.pop_back();
            deq.push_back(compWidth[i+h][j]);
            if (best < deq[0]
                || (best == deq[0]
                    && (i < pos.first 
                        || (i == pos.first && j < pos.second)))) {
                best = deq[0];
                pos = {i, j};
            }
        }
    }
    
    return {pos.first, pos.second};
}