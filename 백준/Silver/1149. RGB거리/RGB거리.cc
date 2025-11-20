#include <iostream>
#include <vector>

using namespace std;

int getMin(int a, int b) {
    return a < b ? a : b;
}

vector<int> getOther(int c) {
    if (0 == c) return {1, 2};
    if (1 == c) return {0, 2};
    return {0, 1};
}

int main() {
    int N;
    cin >> N;
    vector<vector<int>> costs;
    vector<int> candi = {0, 1, 2};

    for (int i = 0; i < N; i++) {
        vector<int> temp;
        for (int j = 0; j < 3; j++) {
            int v;
            cin >> v;
            temp.push_back(v);
        }
        costs.push_back(temp);
    }

    for (int i = 1; i < N; i++) {
        for (int c : candi) {
            vector<int> others = getOther(c);
            costs[i][c] += getMin(costs[i-1][others[0]], costs[i-1][others[1]]);
        }
    }

    int min = getMin(getMin(costs[N-1][0], costs[N-1][1]), costs[N-1][2]);
    cout << min;
    return 0;
}