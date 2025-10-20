#include <cmath>
#include <queue>

using namespace std;

class Node {
private:
    int plusCount;
    int timesCount;
    int left;
    bool complete;
    bool beforeIsPlus;
    bool beforeBeforeIsPlus;
public:
    Node(int left) : left(left), plusCount(0), timesCount(0), complete(false), beforeIsPlus(false), beforeBeforeIsPlus(false) { }
    
    void put(bool isPlus) {
        if (!complete) {
            if (beforeIsPlus && beforeBeforeIsPlus && !isPlus) {
                complete = true;
            } else {
                beforeBeforeIsPlus = beforeIsPlus;
                beforeIsPlus = isPlus;
            }
        }
        if (isPlus) {
            plusCount++;
            left--;
        } else {
            timesCount++;
            left /= 3;
        }
    }
    
    bool isValid() {
        bool a = (pow(3, (plusCount / 2 - timesCount)) <= left
                && timesCount * 2 <= plusCount
                && left >= 1);
        return a;
    }
    
    bool isDividable() {
        return (left % 3 == 0);
    }
    
    bool isFit() {
        return complete && left == 1 && timesCount * 2 == plusCount;
    }
};

int solution(int n) {
    Node baseNode(n);
    int count = 0;
    
    queue<Node> q;
    q.push(baseNode);
    while(!q.empty()) {
        Node n = q.front();
        q.pop();
        
        if (n.isFit()) {
            count++;
            continue;
        }
        
        if (n.isDividable()) {
            Node newOne = n;
            newOne.put(false);
            if (newOne.isValid()) {
                q.push(newOne);
            }
        }
        Node newOne = n;
        newOne.put(true);
        if (newOne.isValid()) {
            q.push(newOne);
        }
    }
    
    return count;
}