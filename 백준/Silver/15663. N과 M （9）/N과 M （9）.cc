#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vecSub(vector<int> vec, int v) {
    vec.erase(find(vec.begin(), vec.end(), v));
    return vec;
}

void recur(vector<int> nVec, int m, vector<int> vec) {
    if (vec.size() == m) {
        for (int v : vec) cout << v << " ";
        cout << "\n";
        return;
    }

    int before = 10001;
    for (int newV : nVec) {
        if (before == newV) {
            continue;
        }
        before = newV;
        vector<int> temp = vec;
        temp.push_back(newV);
        recur(vecSub(nVec, newV), m, temp);
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

    recur(nVec, M, {});

    return 0;
}
