#include <iostream>
#include <queue>
#include <utility>
using namespace std;

class Node {
public:
    int val, count;
    Node(int val, int count = 0) { this->val = val; this->count = count; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int val;
    cin >> val;

    queue<Node> q;
    q.push(Node(val));

    while(true) {
        Node target = q.front();
        if (target.val == 1) { break; }
        q.pop();
        if (target.val % 2 == 0) {
            q.push(Node(target.val/2, target.count+1));
        }
        if (target.val % 3 == 0) {
            q.push(Node(target.val/3, target.count+1));
        }
        q.push(Node(target.val - 1, target.count+1));
    }
    cout << q.front().count;
}
