#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int N, M;
    cin >> N >> M;
    vector<vector<int>> nums(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> nums[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        int mV = -1/*- 1은 범위 밖 */, mC = 0;
        for (int j = 0; j < N; j++) {
            mC = (mV == nums[i][j]) ? mC+1 : 1;
            mV = nums[i][j];
            if (mC >= M) {
                cnt++;
                break;
            }
        }
    }
    for (int j = 0; j < N; j++) {
        int mV = -1/*- 1은 범위 밖 */, mC = 0;
        for (int i = 0; i < N; i++) {
            mC = (mV == nums[i][j]) ? mC+1 : 1;
            mV = nums[i][j];
            if (mC >= M) {
                cnt++;
                break;
            }
        }
    }

    cout << cnt;

    return 0;
}