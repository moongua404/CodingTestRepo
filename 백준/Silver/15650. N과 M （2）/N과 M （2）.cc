#include <iostream>
#include <vector>

using namespace std;

void recur(int n, int m, vector<int> vec) {
    if (vec.size() == m) {
        for (int v : vec) cout << v << " ";
        cout << "\n";
        return;
    }
    int min = vec[vec.size()-1];
    for (int i = min+1; i <= n; i++) {
        vector<int> temp = vec;
        temp.push_back(i);
        recur(n, m, temp);
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        recur(N, M, {i});
    }

    return 0;
}
