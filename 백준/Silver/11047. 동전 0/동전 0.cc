#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, K, count = 0;
    int* arr;

    cin >> N >> K;
    arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[N - 1 - i];
    }

    for (int i = 0; i < N; i++) {
        while(true) {
            if (K / arr[i] == 0) {
                break;
            }
            K -= arr[i];
            count++;
        }
    }

    cout << count;
}