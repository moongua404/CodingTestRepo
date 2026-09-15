#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    int minV = 0x7FFFFFFF, maxV = 0;
    vector<vector<int>> scores(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> scores[i][j];
            if (minV > scores[i][j]) minV = scores[i][j];
            if (maxV < scores[i][j]) maxV = scores[i][j];
        }
    }

    int ans = 0x7FFFFFFF;
    for (int lb = minV; lb <= maxV; lb++) {
        if (lb > scores[0][0]) continue;
        vector<vector<int>> ub(N, vector<int>(N, 0x7FFFFFFF));
        ub[0][0] = scores[0][0];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i+1 < N && scores[i+1][j] >= lb
                        && ub[i+1][j] > max(ub[i][j], scores[i+1][j])) {
                    ub[i+1][j] = max(ub[i][j], scores[i+1][j]);
                }
                if (j+1 < N && scores[i][j+1] >= lb
                        && ub[i][j+1] > max(ub[i][j], scores[i][j+1])) {
                    ub[i][j+1] = max(ub[i][j], scores[i][j+1]);
                }
            }
        }
        if (ans > ub[N-1][N-1] - lb) ans = ub[N-1][N-1] - lb;
    }
    cout << ans;

    return 0;
}
