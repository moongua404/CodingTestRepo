#include <iostream>
using namespace std;

bool submit[30];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T, N;
    cin >> T;
    for (int trial = 0; trial < T; trial++) {
        cin >> N;
        int* arr = new int[N+1];
        arr[0] = 1;
        arr[1] = 0;
        for (int i = 0; i < N+1; i++) {
            if (i == 0 || i == 1) { continue; }
            arr[i] = arr[i-2] + arr[i-1];
        }
        cout << arr[N] << ' ';
        arr[0] = 0;
        arr[1] = 1;
        for (int i = 0; i < N+1; i++) {
            if (i == 0 || i == 1) { continue; }
            arr[i] = arr[i-2] + arr[i-1];
        }
        cout << arr[N] << '\n';
    }
}