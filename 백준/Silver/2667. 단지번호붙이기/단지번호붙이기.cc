#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    bool** map;
    queue<pair<int, int> > q;
    vector<int> res;
    pair<int, int> dirs[4] = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, 1), make_pair(0, -1) };

    cin >> N;
    map = new bool*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new bool[N];
        for (int j = 0; j < N; j++) {
            q.push(make_pair(i, j));
            char v;
            cin >> v;
            map[i][j] = (v == '1') ? true : false;
        }
    }

    while(!q.empty()) {
        pair<int, int> item = q.front();
        q.pop();
        if (map[item.first][item.second]) {
            map[item.first][item.second] = false;
            int v = 1;
            queue<pair<int, int> > temp;
            temp.push(item);
            while(!temp.empty()) {
                pair<int, int> pos = temp.front();
                temp.pop();
                for (pair<int, int> dir: dirs) {
                    int first = pos.first + dir.first;
                    int second = pos.second + dir.second;
                    if (0 <= first && first < N && 0 <= second && second < N && map[first][second]) {
                        map[first][second] = false;
                        v++;
                        temp.push(make_pair(first, second));
                    }
                }
            }
            res.push_back(v);
        }
    }
    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for (auto iter = res.begin(); iter < res.end(); iter++) {
        cout << *iter << '\n';
    }

    return 0;
}