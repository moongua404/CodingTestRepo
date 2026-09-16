#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;

    vector<vector<bool>> coins(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int v;
            cin >> v;
            coins[i][j] = (v == 1);
        }
    }

    int maxV = 0;
    for (int i = 0; i < N-2; i++) {
        for (int j = 0; j < N-2; j++) {
            int cnt = 0;
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    cnt += coins[i+a][j+b];
                }
            }
            if (cnt > maxV) maxV = cnt;
        }
    }

    cout << maxV;

    return 0;
}