/*
"인접한" 두개를 임의로 골라
 - 더 큰 풍선을 터트려 (작은거만 남겨)
 - 딱 한 번 더 작은걸 터트릴 "수" 있음 (큰걸 남길 수 있음)
-> k번째 풍선의 경우 [...k-1]나 [k+1...] 중 한쪽이 낮으면 살아남을 수 있음
-> 왼쪽 오른쪽 모두 나보다 작다면 불가능

왼쪽 heap + 오른쪽 heap (+ 블랙리스트)
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

auto comp = [](int& a, int& b){return a < b;};

class BlacklistedQ {
    priority_queue<int, vector<int>, greater<int>> blacklist;
    priority_queue<int, vector<int>, greater<int>> q;
    
    void arange() {
        while(!blacklist.empty()
              && !q.empty()
              && blacklist.top() == q.top()) {
            blacklist.pop();
            q.pop();
        }
    }
public:
    BlacklistedQ() { }
    BlacklistedQ(vector<int> v) {
        for (int t : v) {
            q.push(t);
        }
    }
    
    int min() {
        if (q.empty()) return 0x7FFFFFFF;
        return q.top();
    }
    
    void add(int t) {
        q.push(t);
        arange();
    }
    
    void del(int t) {
        blacklist.push(t);
        arange();
    }
};

int solution(vector<int> a) {
    BlacklistedQ left;
    BlacklistedQ right(a);
    
    int acc  = 0;
    for (int v : a) {
        right.del(v);
        if (left.min() > v || right.min() > v) {
            acc++;
        }
        left.add(v);
    }
    
    return acc;
}