#include <iostream>

using namespace std;

void solution() {
    int N;
    cin >> N;
    int* arr = new int[N];
    int* rise = new int[N];
    int* fall = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        int max = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] < arr[i] && rise[j] >= max) {
                max = rise[j]+1;
            }
        }
        rise[i] = max;
    }

    for (int i = N-1; i >= 0; i--) {
        int max = 0;
        for (int j = N-1; j > i; j--) {
            if (arr[j] < arr[i] && fall[j] >= max) {
                max = fall[j]+1;
            }
        }
        fall[i] = max;
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        if (rise[i] + fall[i] >= max) {
            max = rise[i] + fall[i] + 1;
        }
    }

    cout << max;
}

int main() {
    solution();

    return 0;
}

/*
arr : 1 5 2 1 4 3 4 5 2 1

n까지의
상승의 최대를 쭉 구하고
하강의 최대를 쭉 구하면?

원래 1 5 2 1 4 3 4 5 2 1
상승 0 1 1 0 2 2 3 4 1 0
하강 0 4 1 0 3 2 2 2 1 0
합계 0 5 2 0 5 4 5 6 1 0
보정 1 6 3 1 6 5 6 7 2 1
=> max : 7
*/