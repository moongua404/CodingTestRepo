#include <iostream>
using namespace std;

void run() {
    int k, n;
    cin >> k >> n;
    int** arr = new int*[k];
    for (int i = 0; i < k+1; i++) {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                arr[i][j] = j+1;
            } else if (j == 0) {
                arr[i][j] = arr[i-1][j];
            } else {
                arr[i][j] = arr[i-1][j] + arr[i][j-1];
            }
        }
    }
    cout << arr[k][n-1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int TestCaseCount;
    cin >> TestCaseCount;

    for (int i = 0; i < TestCaseCount; i++) {
        run();
    }

    return 0;
}

/*
1   2   3   4   5   6   7   8   9   10
1   3   6   10  15  21  28  36  45  55
1   4   10  20  35  56  84  120 165 220
1   5   15  35  70  126 210 330 495 715

*/