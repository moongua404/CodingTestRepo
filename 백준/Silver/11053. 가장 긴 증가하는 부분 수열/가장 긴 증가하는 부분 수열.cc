#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int v;
    int q;

    Node(int v, int q) : v(v), q(q) {}
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = N-1; i >= 0; i--) {
        cin >> A[i];
    }

    vector<Node> res;
    for (int a : A) {
        int max = 0;
        for (Node r : res) {
            if (r.v > a && r.q > max) {
                max = r.q;
            }
        }
        res.push_back(Node(a, ++max));
    }

    int max = 0;
    for (Node r : res) {
        if (r.q > max) {
            max = r.q;
        }
    }
    cout << max;
}