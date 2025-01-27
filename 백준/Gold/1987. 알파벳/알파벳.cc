#include <iostream>
#include <utility>
#include <stack>
using namespace std;

class Node {
    int i, j, turn;
    bool passChar[26];
public:
    Node(Node* copy) {
        this->i = copy->i;
        this->j = copy->j;
        this->turn = copy->turn;
        for (int k = 0; k < 26; k++) {
            this->passChar[k] = copy->passChar[k];
        }
    }
    Node(int i = 0, int j = 0) : i(i), j(j) {
        turn = 0;
        for (int k = 0; k < 26; k++) {
            passChar[k] = false;
        }
    }

    bool isValid(char ch) {
        return !passChar[int(ch) - 65];
    }

    void add(char ch) {
        passChar[int(ch) - 65] = true;
        turn++;
    }
    pair<int, int> getIndex() {
        return make_pair(i, j);
    }
    void setIndex(int i, int j) {
        this->i = i;
        this->j = j;
    }
    int getTurn() {
        return turn;
    }
};

class Board {
    int R, C;
    char** board;
public:
    Board(int R, int C) : R(R), C(C) {
        board = new char*[R];
        for (int i = 0; i < R; i++) {
            board[i] = new char[C];
        }
    }
    bool isValid(int i, int j) {
        return (0 <= i && i < R && 0 <= j && j < C);
    }
    void set(int i, int j, char ch) {
        board[i][j] = ch;
    }
    char get(int i, int j) {
        return board[i][j];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int R, C;
    cin >> R >> C;

    Board board(R, C);
    stack<Node> cases;
    pair<int, int> dirs[4] = {make_pair(1, 0), make_pair(0, 1), make_pair(-1, 0), make_pair(0, -1)};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char ch;
            cin >> ch;
            board.set(i, j, ch);
        }
    }

    Node base = Node(0, 0);
    base.add(board.get(0, 0));
    cases.push(base);

    int max = 0;

    while(!cases.empty()) {
        Node item = cases.top();
        cases.pop();
        if (item.getTurn() > max) {
            max = item.getTurn();
        }

        for (pair<int, int> dir : dirs) {
            int i = item.getIndex().first + dir.first;
            int j = item.getIndex().second + dir.second;
            if (board.isValid(i, j) && item.isValid(board.get(i, j))) {
                Node newOne = Node(item);
                newOne.add(board.get(i, j));
                newOne.setIndex(i, j);
                cases.push(newOne);
            }
        }
    }

    cout << max;

    return 0;
}