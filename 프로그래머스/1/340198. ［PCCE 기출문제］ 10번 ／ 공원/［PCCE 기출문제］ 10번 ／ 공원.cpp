/*
limitation
 - 매트는 길어도 20, 많아야 10 종류
 - 공원은 넓어야 50 by 50
 - worst : 50 * 50 * 10 * 20 * 20 = 10,000,000 <- 할 만 한데?

greedy + bruteforce?

모든 좌표를 순회하며 (50 by 50)
    모든 종류의 길이에 대해 (10)
        하나 하나 확인해보며 (20 by 20)
            최대를 계산
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    string EMPTY = "-1";
    
    int x = park.size();
    int y = park[0].size();
    bool** board = new bool*[x];
    for (int i = 0; i < x; i++) {
        board[i] = new bool[y];
    }
    
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            board[i][j] = (park[i][j] == EMPTY);
        }
    }
    
    int max = -1;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            if (!board[i][j]) continue;
            for (int mat : mats) {
                if (mat <= max) continue;
                bool able = true;
                for (int offx = 0; offx < mat; offx++) {
                    for (int offy = 0; offy < mat; offy++) {
                        if (i + offx < x && j + offy < y
                            && board[i + offx][j + offy]) {
                            continue;
                        }
                        able = false;
                        break;
                    }
                    if (able) continue;
                    break;
                }
                if (able) {
                    max = mat;
                }
            }
        }
    }
    
    return max;
}