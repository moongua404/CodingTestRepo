#include <iostream>

using namespace std;

void testCase() {
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    arr[0] = 1;
    for (int i = 0; i < n; i++) {
        if (i+1 < n+1) {
            arr[i+1] += arr[i];
        }
        if (i+2 < n+1) {
            arr[i+2] += arr[i];
        }
        if (i+3 < n+1) {
            arr[i+3] += arr[i];
        }
    }

    cout << arr[n] << '\n';
}

void solution() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        testCase();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();

    return 0;
}
