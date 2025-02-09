#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    int* arr = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr+N);

    int sum = 0;
    int v = int(round(0.15*N));
    for (int i = v; i < N - v; i++) {
        sum += arr[i];
    }
    if (sum == 0) {
        cout << 0;
        return 0;
    }
    cout << round(float(sum) / (N - 2 * v));

    return 0;
}