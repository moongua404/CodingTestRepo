#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
    queue<int> path;
    bool polluted;

    Node() {
        polluted = false;
    }

    void add(int v) {
        path.push(v);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int NumOfCom, NumOfLinks;
    cin >> NumOfCom >> NumOfLinks;

    Node* links = new Node[NumOfCom];
    for(int i = 0; i < NumOfLinks; i++) {
        int a, b;
        cin >> a >> b;
        links[a-1].add(b);
        links[b-1].add(a);
    }

    queue<int> q;
    int pollutionCount = -1;

    q.push(1);
    while(!q.empty()) {
        Node* cur = &links[q.front()-1];
        q.pop();
        if (!cur->polluted) {
            cur->polluted = true;
            pollutionCount++;
            while(!cur->path.empty()) {
                q.push(cur->path.front());
                cur->path.pop();
            }
        }
    }
    cout << pollutionCount;
}
/*
그냥 큐에 담아, 돌려, 없애
*/