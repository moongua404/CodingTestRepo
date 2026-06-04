/*
1M cells, 250k skills
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int ySize = board.size();
    int xSize = board[0].size();
    vector<vector<int>> diff(ySize+1);
    for (int i = 0; i < ySize+1; i++) {
        diff[i].resize(xSize+1);
    }
    
    for (vector<int> effect : skill) { // [type, r1, c1, r2, c2, degree]
        int head = (effect[0] == 1) ? -1 : 1;
        int v = head * effect[5];
        diff[effect[1]][effect[2]] += v;
        diff[effect[1]][effect[4]+1] -= v;
        diff[effect[3]+1][effect[2]] -= v;
        diff[effect[3]+1][effect[4]+1] += v;
    }
    
    int cnt = 0;
    vector<int> diffline(xSize);
    
    for (int i = 0; i < ySize; i++) {
        int acc = 0;
        for (int j = 0; j < xSize; j++) {
            diffline[j] += diff[i][j];
            acc += diffline[j];
            if (board[i][j] + acc > 0) cnt++;
        }
    }
    return cnt;
}