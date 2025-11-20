#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    long v;
    int i;
    Node(long v, int i) : v(v), i(i) {}
};

int main() {
    int A, B;
    cin >> A >> B;

    queue<Node> q;
    q.push(Node(A, 1));

    long min = 0x7FFFFFFFFFFFFFFF;

    while(!q.empty()) {
        Node n = q.front();
        q.pop();
        
        if (n.v > B || n.i > min) {
            continue;
        }
        if (n.v == B) {
            min = min < n.i ? min : n.i;
            continue;
        }

        q.push(Node(n.v * 2, n.i+1));
        q.push(Node(n.v * 10 + 1, n.i+1));
    }

    min = min == 0x7FFFFFFFFFFFFFFF ? -1 : min;
    cout << min;

    return 0;
}
