/*
시작과 목표의 차이를 뒤집을 수 있느냐. 
뒤집어 보면 되겠지머
greedy하게
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> beginning, vector<vector<int>> target) {
    int h = target.size(), w = target[0].size();
    vector<vector<bool>> diff(h);
    
    // 초기화
    for (int i = 0; i < h; i++) {
        diff[i].resize(w);
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            diff[i][j] = (beginning[i][j] != target[i][j]);
        }
    }
    
    vector<int> xFilter(h);
    vector<int> yFilter(w);
    
    int xc = 0, yc = 0;
    for (int i = 0; i < h; i++) {
        if (!diff[i][0]) continue;
        xFilter[i] = true;
        xc++;
    }
    for (int j = 0; j < w; j++) {
        if (diff[0][j] == xFilter[0]) continue;
        yFilter[j] = true;
        yc++;
    }
    
    // 탈락
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (diff[i][j] != xFilter[i] != yFilter[j]) return -1;
        }
    }
    
    // 결과 중 최소
    if (xc + yc < w + h - xc - yc) return xc + yc;
    return w + h - xc - yc;
}