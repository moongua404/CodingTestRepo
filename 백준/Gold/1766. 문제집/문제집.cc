/*
최대 문제의 수 : 32,000

구현 방안
Node
 - 필드 int n, List<*> next(좋은 문제)

문제 처리 방안 (입력 처리) + O(n log n)
 - Map<int, *Node>로 초기 Node 표기 -- 배열로 대체 가능
 - 이후에 풀기 좋은 문제를 Map에서 지우고 이전 문제의 next에 등록
 - 모든 Node를 순회하며 Next를 정렬

출력 처리 방안 n log n
 - Map에 있는 Node들로 PriorityQueue를 구성
 - 가장 작은 값을 pop한 후 출력
 - next가 있다면 heap에 다시 넣음

*/

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int n, before;
    vector<Node*> next;
    
    Node() {}
    Node(int n) { this->n = n; before = 0; }

    void addBefore(){before += 1;}
    void addNext(Node* next) { this->next.push_back(next); }
    bool operator<(const Node& other) const { return this->n > other.n; }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    
    Node* nodes = new Node[N];
    for (int i = 0; i < N; i++) {
        nodes[i] = Node(i+1);
    }

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        nodes[A-1].addNext(&nodes[B-1]);
        nodes[B-1].addBefore();
    }

    priority_queue<Node> pq;
    for (int i = 0; i < N; i++) {
        if (nodes[i].before != 0) continue;
        pq.push(nodes[i]);
    }

    while(!pq.empty()) {
        Node pick = pq.top();
        pq.pop();
        cout << pick.n << " ";
        for (Node* nextPtr : pick.next) {
            nextPtr->before--;
            if (nextPtr->before == 0) {
                pq.push(*nextPtr);
            }
        }
    }

    return 0;
}