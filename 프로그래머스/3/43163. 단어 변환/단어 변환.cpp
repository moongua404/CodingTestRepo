#include <string>
#include <vector>
#include <queue>

using namespace std;

int getDiff(string s1, string s2, int size) {
    int acc = 0;
    for (int i = 0; i < size; i++) {
        if (s1[i] != s2[i]) { acc++; }
    }
    return acc;
}

class Node {
public:
    string s;
    int order;
    bool visited;
    vector<Node*> nexts;
    Node(string s) : s(s), order(0), visited(false) { }
};

int solution(string begin, string target, vector<string> words) {
    int size = begin.length();
    vector<Node> nodes;
    nodes.push_back(Node(begin));
    for (string word : words) {
        nodes.push_back(word);
    }

    for (int i = 0; i < nodes.size(); i++) {
        for (int j = 0; j < nodes.size(); j++) {
            if (i != j && getDiff(nodes[i].s, nodes[j].s, size) == 1) {
                nodes[i].nexts.push_back(&nodes[j]);
            }
        }
    }
    
    queue<Node*> q;
    nodes[0].visited = false;
    q.push(&nodes[0]);
    int min = 0xFFFF;
    while(!q.empty()) {
        Node* n = q.front();
        q.pop();
        
        if (n->s == target && n->order < min) {
            min = n->order;
            continue;
        }
        
        for (int i = 0; i < n->nexts.size(); i++) {
            if (n->nexts[i]->visited && n->nexts[i]->order <= n->order) { continue; }
            n->nexts[i]->visited = true;
            n->nexts[i]->order = n->order + 1;
            q.push(n->nexts[i]);
        }
    }
    
    if (min == 0xFFFF) { return 0; }
    return min;
}