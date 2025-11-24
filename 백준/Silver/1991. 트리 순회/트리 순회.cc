#include <iostream>
#include <map>

using namespace std;

class Node {
public:
    char ch;
    Node* left;
    Node* right;
    Node(char ch) : ch(ch), left(nullptr), right(nullptr) { }
    Node() : ch(' '), left(nullptr), right(nullptr) { }

    void pre() {
        cout << ch;
        if (left != nullptr) left->pre();
        if (right != nullptr) right->pre();
    }

    void middle() {
        if (left != nullptr) left->middle();
        cout << ch;
        if (right != nullptr) right->middle();
    }

    void post() {
        if (left != nullptr) left->post();
        if (right != nullptr) right->post();
        cout << ch;
    }
};

class Tree {
public:
    map<char, Node> nodes;
    
    bool isExist(char ch) {
        return (nodes.find(ch) != nodes.end());
    }

    void put(char ch) {
        if (!isExist(ch)) {
            nodes.insert({ch, Node(ch)});
        }
    }

    void setLeft(char root, char left) {
        put(left);
        nodes[root].left = &(nodes[left]);
    }

    void setRight(char root, char right) {
        put(right);
        nodes[root].right = &(nodes[right]);
    }
};

void solution() {
    int N;
    cin >> N;
    Tree tree;

    for (int i = 0; i < N; i++) {
        char root, left, right;
        cin >> root >> left >> right;
        tree.put(root);
        if (left != '.') {
            tree.setLeft(root, left);
        }
        if (right != '.') {
            tree.setRight(root, right);
        }
    }

    tree.nodes['A'].pre();
    cout << "\n";
    tree.nodes['A'].middle();
    cout << "\n";
    tree.nodes['A'].post();
    cout << "\n";
}

int main() {
    solution();

    return 0;
}