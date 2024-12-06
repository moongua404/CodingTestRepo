#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
    int prev;
    char op;
    Node(int prev = -1, char op = ' ') { this->prev = prev; this->op = op; }
};

int calL(int v) {
    int b = v / 1000;
    v -= b * 1000;
    v *= 10;
    v += b;
    return v;
}

int calR(int v) {
    int b = v % 10;
    v /= 10;
    v += b * 1000;
    return v;
}

/*
1에서 시작해서 3으로 간다고 가정해보자
printUntil(map, 3, 1)
map[2]에는 1과 'D'가 적혀있음
map[4]에는 2와 'D'가 적혀있음
map[3]에는 4와 'S'가 적혀있음
*/

void printUntil(Node* map, int cur, int target) {
    if (map[cur].prev != target) {
        printUntil(map, map[cur].prev, target);
    }
    cout << map[cur].op;
}

void dslr() {
    int A, B;
    cin >> A >> B;

    Node map[10000];
    queue<int> q;
    q.push(A);

    while(!q.empty()) {
        if (q.front() == B) {
            break;
        }
        int D = (q.front()*2)%10000;
        int S = ((q.front()-1)+10000) % 10000;
        int L = calL(q.front());
        int R = calR(q.front());
        if (map[D].op == ' ') {
            q.push(D);
            map[D] = Node(q.front(), 'D');
        }
        if (map[S].op == ' ') {
            q.push(S);
            map[S] = Node(q.front(), 'S');
        }
        if (map[L].op == ' ') {
            q.push(L);
            map[L] = Node(q.front(), 'L');
        }
        if (map[R].op == ' ') {
            q.push(R);
            map[R] = Node(q.front(), 'R');
        }
        q.pop();
        
    }
    printUntil(map, B, A);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        dslr();
    }
}

/*
Node : int(이전 위치) + char(수행한 연산)
만개짜리 Node 배열을 만들어
위치를 하나씩 찾아
*/