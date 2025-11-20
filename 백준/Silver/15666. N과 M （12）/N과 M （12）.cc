#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recur(vector<int> nVec, int m, vector<int> vec) {
    if (vec.size() == m) {
        for (int v : vec) cout << v << " ";
        cout << "\n";
        return;
    }

    for (int newV : nVec) {
        if (!vec.empty() && vec[vec.size()-1] > newV) {
            continue;
        }
        vector<int> temp = vec;
        temp.push_back(newV);
        recur(nVec, m, temp);
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> nVec(N);
    for (int i = 0; i < N; i++) {
        cin >> nVec[i];
    }
    sort(nVec.begin(), nVec.end());
    nVec.erase(unique(nVec.begin(), nVec.end()), nVec.end());

    recur(nVec, M, {});

    return 0;
}
