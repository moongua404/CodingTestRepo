#include <iostream>
using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        arr[i] = i+1;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        swap(arr[a-1], arr[b-1]);
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
}