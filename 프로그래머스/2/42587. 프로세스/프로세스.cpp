#include <string>
#include <vector>
#include <queue>

using namespace std;

class Tag {
public:
    int p;
    bool tagged;
    
    Tag(int p, bool tagged = false) : p(p), tagged(tagged) { }
};

int solution(vector<int> priorities, int location) {
    queue<Tag> q;
    int targetP = priorities[location];
    vector<int> lefts = {0,0,0,0,0,0,0,0,0,0};
    int count = 0;
    
    for (int i = 0; i < priorities.size(); i++) {
        if (priorities[i] >= targetP) {
            lefts[priorities[i]]++;
            if (i == location) { q.push(Tag(priorities[i], true)); }
            else { q.push(priorities[i]); }
        }
    }
    
    for (int i = 9; i >= targetP; i--) {
        while(lefts[i] > 0) {
            if (q.front().p == i) {
                count++;
                lefts[i]--;
                if (i == targetP && q.front().tagged) {
                    break;
                }
                q.pop();
            } else {
                q.push(q.front());
                q.pop();
            }
        }
    }
    
    return count;
}