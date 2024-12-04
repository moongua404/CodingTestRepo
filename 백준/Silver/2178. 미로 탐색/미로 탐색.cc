#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Node {
public:
    int x, y, count;
    Node(int x, int y, int count = 1) {
        this->x = x; this->y = y; this->count = count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;
    bool** map = new bool*[N];
    for (int i = 0; i < N; i++) {
        map[i] = new bool[M];
    }

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++) {
            map[i][j] = (s[j] == '1') ? true : false;
        }
    }

    queue<Node> q;
    q.push(Node(0, 0));
    while(true) {
        Node pos = q.front();
        if (pos.x == N-1 && pos.y == M-1) {
            break;
        }
        q.pop();
        if (pos.x >= 0 && pos.x < N && pos.y >= 0 && pos.y < M && map[pos.x][pos.y]) {
            map[pos.x][pos.y] = false;
            q.push(Node(pos.x+1, pos.y, pos.count+1));
            q.push(Node(pos.x-1, pos.y, pos.count+1));
            q.push(Node(pos.x, pos.y+1, pos.count+1));
            q.push(Node(pos.x, pos.y-1, pos.count+1));
        }
    }
    cout << q.front().count;
}
