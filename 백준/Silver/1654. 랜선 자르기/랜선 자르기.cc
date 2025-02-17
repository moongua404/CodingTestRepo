#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long N, K, min = 1, max = 0;
    cin >> N >> K;
    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        max += arr[i];
    }

    while(min != max) {
        long long mid = (min + max) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            sum += arr[i] / mid;
        }
        if (sum >= K) {
            min = mid;
            if (max - min == 1) {
                break;
            }
        } else {
            max = mid;
        }
    }

    cout << min;

    return 0;
}