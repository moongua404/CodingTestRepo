#include <iostream>
#include <deque>
using namespace std;

class Node {
public:
    int v, order;
    Node (int v = 0, int order = 0) : v(v), order(order) {}
};

void printerQueue() {
    int N, M;
    deque<Node> printerQ;
    int priority[9];
    for (int i = 0; i < 9; i++) {
        priority[i] = 0;
    }

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        priority[v-1]++;
        printerQ.push_back(Node(v, i));
    }

    int idx = 8;
    int orderCount = 0;
    while(idx >= 0) {
        if (priority[idx] == 0) {
            idx--;
            continue;
        }
        Node item = printerQ.front();
        printerQ.pop_front();
        if (item.v == idx+1) {
            orderCount++;
            priority[idx]--;
            if (item.order == M) {
                break;
            }
        } else {
            printerQ.push_back(item);
        }
    }

    cout << orderCount << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCaseCount;
    cin >> testCaseCount;
    for (int testCase = 0; testCase < testCaseCount; testCase++) {
        printerQueue();
    }

    return 0;
}