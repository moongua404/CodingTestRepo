/*
Worst
 - Node : 10k
 - Event : 100k
E Log(N)

필요한 거
 - 노드의 층 (각 노드가 몇층인지)
 - 부모
*/

#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Node {
    int gain;
    Node* parent;
public:
    Node() : gain(0), parent(nullptr) { }
    
    void setParent(Node* parent) {
        this->parent = parent;
    }
    
    Node* getParent() {
        return parent;
    }
    
    void addGain(int n) {
        gain += n;
    }
    
    int getGain() {
        return gain;
    }
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    int nodeSize = enroll.size();
    vector<Node> nodes(nodeSize);
    map<string, Node*> nodeMap;
    for (int i = 0; i < nodeSize; i++) {
        nodeMap.insert({enroll[i], &nodes[i]});
    }
    
    for (int i = 0; i < referral.size(); i++) {
        if (referral[i] == "-") continue;
        nodes[i].setParent(nodeMap[referral[i]]);
    }
    
    for (int i = 0; i < seller.size(); i++) {
        Node* node = nodeMap[seller[i]];
        int price = amount[i] * 100;
        while(node != nullptr) {
            int left = price * 0.1;
            node->addGain(price - left);
            node = node->getParent();
            price = left;
        }
    }
    
    vector<int> answer(nodeSize);
    for (int i = 0; i < nodeSize; i++) {
        answer[i] = nodes[i].getGain();
    }
    return answer;
}