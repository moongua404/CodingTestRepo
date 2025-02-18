#include <iostream>
using namespace std;

long long padoban(long long v) {
    long long* arr = new long long[v];
    for (long long i = 0; i < v; i++) {
        if (i < 5) {
            arr[i] = (i < 3) ? 1 : 2;
        } else {
            arr[i] = arr[i-1] + arr[i-5];
        }
    }
    return arr[v-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        long long v;
        cin >> v;
        cout << padoban(v) << '\n';
    }

    return 0;
}