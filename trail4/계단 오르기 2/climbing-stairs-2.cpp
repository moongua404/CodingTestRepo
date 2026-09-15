#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    vector<int> coins(N+2); // [계단위치+2]
    for (int i = 2; i < N+2; i++) {
        cin >> coins[i];
    }

    vector<vector<int>> dp(N+2, vector<int>(4)); // [계단위치+2][1계단 오른 횟수]
    for (int i = 0; i < 4; i++) {
        dp[0][i] = -1000001;
        dp[1][i] = 0;
    }
    for (int i = 2; i < N+2; i++) {
        dp[i][0] = dp[i-2][0] + coins[i];
        for (int j = 1; j < 4; j++) {
            int v1 = dp[i-1][j-1] + coins[i];
            int v2 = dp[i-2][j] + coins[i];
            dp[i][j] = (v1 > v2) ? v1 : v2;
        }
    }
    int maxV = 0;
    for (int i = 0; i < 4; i++) {
        if (dp[N+1][i] > maxV) maxV = dp[N+1][i];
    }
    cout << maxV;

    return 0;
}