#include <string>
#include <vector>

using namespace std;

class Node {
public:
    Node* next;
    char ch;
    bool isValid = true;
    
    Node* nextTo(int v) {
        if (!isValid) return next->nextTo(v);
        if (v <= 0) return this;
        if (next == nullptr) return nullptr;
        return next->nextTo(v-1);
    }
    
    Node* find(char ch) {
        if (this->ch == ch) return this;
        if (next == nullptr) return nullptr;
        return this->next->find(ch);
    }
};

string solution(string s, string skip, int index) {
    int A = 97, Z = 122;
    
    Node pivot;
    pivot.ch = 'X';
    pivot.isValid = false;
    
    Node* prev = &pivot;
    for (int i = A; i <= Z; i++) {
        Node* n = new Node();
        n->ch = char(i);
        prev->next = n;
        prev = n;
    }
    prev->next = &pivot;
    
    for (char ch : skip) {
        pivot.find(ch)->isValid = false;
    }
    
    for (int i = 0; i < s.length(); i++) {
        s[i] = pivot.find(s[i])->nextTo(index)->ch;
    }
    
    return s;
}