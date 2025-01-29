#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int X, N;
    cin >> X >> N;

    int* arr = new int[X];
    for (int i = 0; i < X; i++) {
        cin >> arr[i];
    }

    int max, sum = 0, idx = 0, duration = 0;

    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }
    max = sum;
    duration = 1;

    while(idx + N < X) {
        sum += arr[idx+N] - arr[idx];
        if (sum == max) {
            duration++;
        } else if (sum > max) {
            max = sum;
            duration = 1;
        }
        idx++;
    }

    if (sum == 0) {
        cout << "SAD";
    } else {
        cout << max << "\n" << duration;
    }

    return 0;
}