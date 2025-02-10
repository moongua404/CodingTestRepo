#include <iostream>
#include <vector>
using namespace std;

void printLotto(vector<int> vec, int* arr, int arrSize, int lottoCount) {
    if (lottoCount <= 0) {
        for (int v : vec) {
            cout << v << ' ';
        }
        cout << '\n';
        return;
    }
    if (arrSize <= 0) {
        return;
    }
    for (int i = 0; i < arrSize; i++) {
        vector<int> vec2 = vec;
        vec2.push_back(arr[i]);
        printLotto(vec2, arr+(i+1), arrSize-(i+1), lottoCount-1);
    }
}

/*
배열에 있는 작은 숫자부터 순서대로 돌면서
    만약 arrSize에서 더 집을 수 없다 -> -1
    만약 lottoCount가 0이 되었다 -> 쭉 출력

    집어, 재귀 호출(arr+1, arrSize-1, lottoCount--);
    재귀 값 받아서, -1이 아니면 나도 출력;
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    while(true) {
        int N;
        cin >> N;
        if (N == 0) {
            break;
        }
        int* arr = new int[N];
        vector<int> vec;

        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        printLotto(vec, arr, N, 6);
        cout << '\n';
    }
    return 0;
}