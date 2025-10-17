#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    for (int i = 0; i < triangle.size(); i++) {
        for (int j = 0; j <= i; j++) {
            if (i-1 < 0) { continue; }
            if (i == j) {
                triangle[i][j] += triangle[i-1][j-1];
                continue;
            }
            if (j == 0) {
                triangle[i][j] += triangle[i-1][j];
                continue;
            }
            triangle[i][j] +=
                (triangle[i-1][j-1] > triangle[i-1][j]) ?
                triangle[i-1][j-1] : triangle[i-1][j];
        }
    }
    
    int max = 0;
    for (int v : triangle[triangle.size()-1]) {
        if (v > max) { max = v; }
    }
    
    return max;
}