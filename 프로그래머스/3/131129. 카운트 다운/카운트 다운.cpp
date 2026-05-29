/*
싱글 [1...20]
더블 [2,4...40]
트리플 [3,6...60]
불 [50]
각 요소를 선택했지만 optimul을 맞출 수 없다면 최대를 선택

pair<int, int> [다트 수] [싱글/불의 수]
dfs -> bfs
*/

#include <string>
#include <vector>

using namespace std;

struct Node {
    int left;
    pair<int, int> trial; // [total][싱글/불]
    
    Node(int left, pair<int, int> trial) : left(left), trial(trial) { }
    
    Node add(int left, pair<int, int> trial) {
        return Node(
            this->left + left, 
            {this->trial.first+trial.first, this->trial.second+trial.second});
    }
};

bool isLessThan(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

vector<int> solution(int target) {
    vector<Node> q; // 가짜임 사실 스택임
    q.push_back(Node(target, {0, 0}));
    pair<int, int> min = {0x7FFFFFFF, 0x7FFFFFFF};
    while(!q.empty()) {
        Node node = q.back();
        q.pop_back();
        if (isLessThan(min, node.trial)) {
            continue;
        }
        if (node.left == 0) {
            min = node.trial;
            continue;
        }
        
        // 하아드코딩..
        if (node.left >= 3) { // 트리플
            int triple = node.left;
            if (triple > 60) triple = 60;
            if (triple % 3 != 0) triple -= (triple % 3);
            q.push_back(node.add(-triple, {1, 0}));
        }
        
        if (node.left >= 300) {
            continue; // 충분히 크다면 이왕이면 트리플
        }
        
        if (node.left >= 50) { // 불
            q.push_back(node.add(-50, {1, 1}));
            continue; // 충분히 크다면 이왕이면 불
        }
        
        if (node.left >= 50) {
            continue; 
        }
        
        if (node.left >= 2) { // 더블
            int doub = node.left;
            if (doub > 40) doub = 40;
            if (doub % 2 == 1) doub--;
            q.push_back(node.add(-doub, {1, 0}));
        }
        
        int single = node.left; // 싱글
        if (single > 20) single = 20;
        q.push_back(node.add(-single, {1, 1}));
    }
    
    return vector<int>{min.first, min.second};
}