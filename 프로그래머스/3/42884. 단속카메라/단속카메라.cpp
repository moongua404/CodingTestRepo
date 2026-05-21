/*
문제는 겹칠때야
어차피 모든 선분은 검사 구간이 있어야 해. 
그러면 이왕이면 먼저 끝나는 지점에 카메라를 둬버리면
최소성과 보장성을 얻을 수 있어
-> greedy
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Path {
    int start, end;
    
    Path() : start(-500), end(-500) { }
    Path(int start, int end) : start(start), end(end) { }
    
    bool const operator<(const Path other) const {
        return this->end > other.end;
    }
};

int solution(vector<vector<int>> routes) {
    priority_queue<Path> paths;
    for (vector<int> route : routes) {
        paths.push(Path(route[0], route[1]));
    }
    
    int answer = 0;
    int end = -30001;
    while(!paths.empty()) {
        if (paths.top().start <= end) {
            paths.pop();
            continue;
        }
        end = paths.top().end;
        answer++;
    }
    return answer;
}