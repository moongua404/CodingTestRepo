#include <iostream>

using namespace std;

void solution() {
    int N, M;
    cin >> N >> M;
    int* arr = new int[N+1];
    arr[0] = 0;
    for (int i = 1; i < N+1; i++) {
        int v;
        cin >> v;
        arr[i] = arr[i-1] + v;
    }

    for (int c = 0; c < M; c++) {
        int i, j;
        cin >> i >> j;
        cout << arr[j] - arr[i-1] << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();

    return 0;
}
