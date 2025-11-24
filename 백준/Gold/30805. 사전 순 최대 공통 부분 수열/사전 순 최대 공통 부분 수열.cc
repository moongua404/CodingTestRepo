#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution() {
    int N, M;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> M;
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    vector<int> result;
    
    while (true) {
        int max = 0;
        int aIdx, bIdx;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (A[i] == B[j] && A[i] > max) {
                    max = A[i];
                    aIdx = i;
                    bIdx = j;
                }
            }
        }
        if (max == 0) {
            break;
        }
        result.push_back(max);
        A.erase(A.begin(), A.begin() + aIdx + 1);
        B.erase(B.begin(), B.begin() + bIdx + 1);
    }

    cout << result.size();
    if (!result.empty()) {
        cout << "\n";
        for (int v : result) {
            cout << v << " ";
        }
    }
}

int main() {
    solution();

    return 0;
}