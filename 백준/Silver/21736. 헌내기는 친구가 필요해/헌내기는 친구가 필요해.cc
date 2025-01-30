#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M, res = 0;
    char** map;
    stack<pair<int, int> > doyeon;
    pair<int, int> dirs[4] = { make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1) };

    cin >> N >> M;
    map = new char*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new char[M];
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'I') {
                map[i][j] = false;
                doyeon.push(make_pair(i, j));
            }
        }
    }

    while(!doyeon.empty()) {
        pair<int, int> pos = doyeon.top();
        doyeon.pop();
        for (pair<int, int> dir : dirs) {
            int first = pos.first + dir.first;
            int second = pos.second + dir.second;
            if (0 <= first && first < N && 0 <= second && second < M && map[first][second] != 'X') {
                if (map[first][second] == 'P') { res++; }
                map[first][second] = 'X';
                doyeon.push(make_pair(first, second));
            }
        }
    }

    if (res == 0) {
        cout << "TT";
    } else {
        cout << res;
    }
}