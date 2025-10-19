#include <string>
#include <vector>

using namespace std;

class Node {
public:
    int x;
    int y;
    int v;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int x, int y, int v) : x(x), y(y), v(v) { }
};

vector<int> preRecur(Node node) {
    vector<int> v({node.v});
    if (node.left != nullptr) {
        vector<int> vl = preRecur(*node.left);
        for (int l : vl) {
            v.push_back(l);
        }
    }
    if (node.right != nullptr) {
        vector<int> vr = preRecur(*node.right);
        for (int r : vr) {
            v.push_back(r);
        }
    }
    return v;
}

vector<int> postRecur(Node node) {
    vector<int> v;
    if (node.left != nullptr) {
        vector<int> vl = postRecur(*node.left);
        for (int l : vl) {
            v.push_back(l);
        }
    }
    if (node.right != nullptr) {
        vector<int> vr = postRecur(*node.right);
        for (int r : vr) {
            v.push_back(r);
        }
    }
    v.push_back(node.v);
    return v;
}

Node* btRecur(vector<Node*>& nodes) {
    if (nodes.size() == 0) { return nullptr; }
    int maxY = -1;
    Node* standard = nullptr;
    for (Node* node : nodes) {
        if (node->y > maxY) {
            maxY = node->y;
            standard = node;
        }
    }
    
    vector<Node*> left, right;
    for (Node* node : nodes) {
        if (node->x < (*standard).x) {
            left.push_back(node);
        } else if (node->x > (*standard).x) {
            right.push_back(node);
        }
    }
    
    (*standard).left = btRecur(left);
    (*standard).right = btRecur(right);
    return standard;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<Node> nodes;
    vector<Node*> dummy;
    
    for (int i = 0; i < nodeinfo.size(); i++) {
        vector<int> item = nodeinfo[i];
        nodes.push_back(Node(item[0], item[1], i+1));
    }

    for (Node& node : nodes) {
        dummy.push_back(&node);
    }
    
    Node* top = btRecur(dummy);
    
    vector<vector<int>> answer;
    answer.push_back(preRecur(*top));
    answer.push_back(postRecur(*top));
    return answer;
}