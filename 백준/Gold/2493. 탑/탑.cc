#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int v, idx;
    Node(int v, int idx) : v(v), idx(idx) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    stack<Node> tower;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;

        while(!tower.empty()) {
            if (v >= tower.top().v) {
                tower.pop();
            } else {
                cout << tower.top().idx << ' ';
                tower.push(Node(v, i+1));
                break;
            }
        }
        if (tower.empty()) {
            cout << "0 ";
            tower.push(Node(v, i+1));
        }
    }

    return 0;
}