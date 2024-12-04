#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, i, j, k;;
    cin >> N >> M;

    int* arr = new int[N];
    for (int tr = 0; tr < N; tr++) {
        arr[tr] = 0;
    }

    for (int tr = 0; tr < M; tr++) {
        cin >> i >> j >> k;
        for (int r = i; r <= j; r++) {
            arr[r-1] = k;
        }
    }

    for (int tr = 0; tr < N; tr++) {
        cout << arr[tr] << ' ';
    }
}