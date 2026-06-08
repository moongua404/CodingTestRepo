/*
10^12 -> 배열 할당 불가
맵을 쓰되 매번 O(n) 탐색할 수는 없음
Union Find의 기믹(?)을 활용?
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFindLike {
    unordered_map<long long, long long> m; // {방 번호, 다음 방 번호}
    
public:
    long long findOrPut(long long v) {
        if (m.find(v) == m.end()) { // 없으면 put
            m[v] = v+1;
            return v;
        }
        long long next = findOrPut(m[v]); // lazy sort
        m[v] = next;
        return next;
    }
};

vector<long long> solution(long long k, vector<long long> room_number) {
    UnionFindLike uf;
    
    for (long long& v : room_number) {
        v = uf.findOrPut(v);
    }
    
    return room_number;
}