/*
복잡하게 생각할거 있나..?
직사각형들을 맵 위에 직접 그리면서 모두 업데이트 - 어차피 4개여서 ㄱㄴ 맵 크기도 뭐... 넉넉하게
*/

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Node {
    int x, y, t;
    Node(int x, int y, int t = 0) : x(x), y(y), t(t) { }
};

enum Type {
    OUTER, INNER, BORDER
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int MAP_SIZE = 120;
    Node dirs[4] = {Node(0, 1), Node(0, -1), Node(1, 0), Node(-1, 0)};
    
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    
    Type** board = new Type*[MAP_SIZE];
    bool** visited = new bool*[MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++) {
        board[i] = new Type[MAP_SIZE];
        visited[i] = new bool[MAP_SIZE];
        for (int j = 0; j < MAP_SIZE; j++) {
            board[i][j] = Type::OUTER;
            visited[i][j] = false;
        }
    }
    
    for (vector<int> rect : rectangle) {
        for (int i = rect[0] * 2; i <= rect[2] * 2; i++) {
            for (int j = rect[1] * 2; j <= rect[3] * 2; j++) {
                if ((i == rect[0] * 2 || i == rect[2] * 2
                        || j == rect[1] * 2 || j == rect[3] * 2)
                    && !(board[i][j] == Type::INNER)) {
                    board[i][j] = Type::BORDER;
                } else {
                    board[i][j] = Type::INNER;
                }
            }
        }
    }
    
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            if (i == characterX && j == characterY) cout << 'S';
            else if (i == itemX && j == itemY) cout << 'D';
            else if (board[i][j] == INNER) cout << 'O';
            else if (board[i][j] == BORDER) cout << 'X';
            else cout << ' ';
        }
        cout << "\n";
    }
    
    queue<Node> q;
    q.push(Node(characterX, characterY, 0));
    visited[characterX][characterY] = true;
    while(!q.empty()) {
        Node n = q.front();
        q.pop();
        if (n.x == itemX && n.y == itemY) {
            return n.t/2; // 어차피 queue니까 발견한게 최소. 
        }
        for (Node dir : dirs) {
            int newX = n.x + dir.x;
            int newY = n.y + dir.y;
            if (board[newX][newY] == BORDER && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push(Node(newX, newY, n.t+1));
            }
        }
    }
    
    // 도달할 수 없는 영역
    return -500;
}