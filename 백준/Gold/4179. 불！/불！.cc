#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int x, y;
    Node() {}
    Node(int x, int y) : x(x), y(y) {}
};

class Map {
    bool** map;
    int maxX, maxY;

public:
    Map(int maxY, int maxX) : maxX(maxX), maxY(maxY) {
        map = new bool*[maxY];
        for (int y = 0; y < maxY; y++) {
            map[y] = new bool[maxX];
        }
    }

    bool isEdge(int x, int y) {
        return (x == 0 || x == maxX-1 || y == 0 || y == maxY-1);
    }

    bool isMovable(int x, int y) {
        if (x < 0 || x >= maxX || y < 0 || y >= maxY) {
            return false;
        }
        return map[y][x];
    }

    void set(int x, int y, bool v) {
        map[y][x] = v;
    }
};

int main() {
    int R, C;
    queue<Node> jihoon, fire, cache;
    Node dirs[4] = {Node(1, 0), Node(-1, 0), Node(0, 1), Node(0, -1)};

    cin >> R >> C;
    Map map(R, C);

    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            char ch;
            cin >> ch;
            if (ch == '.') {
                map.set(x, y, true);
            } else {
                map.set(x, y, false);
                if (ch == 'J') {
                    jihoon.push(Node(x, y));
                } else if (ch == 'F') {
                    fire.push(Node(x, y));
                }
            }
        }
    }

    int turn = 0;
    bool found = false;

    while(!found && !jihoon.empty()) {
        turn++;

        while(!fire.empty()) {
            Node item = fire.front();
            fire.pop();
            for (Node dir : dirs) {
                if (map.isMovable(item.x + dir.x, item.y + dir.y)) {
                    map.set(item.x + dir.x, item.y + dir.y, false);
                    cache.push(Node(item.x + dir.x, item.y + dir.y));
                }
            }
        }
        while (!cache.empty()) {
            fire.push(cache.front());
            cache.pop();
        }

        while(!jihoon.empty()) {
            Node item = jihoon.front();
            jihoon.pop();
            if (map.isEdge(item.x, item.y)) {
                found = true;
                break;
            }
            for (Node dir : dirs) {
                if (map.isMovable(item.x + dir.x, item.y + dir.y)) {
                    map.set(item.x + dir.x, item.y + dir.y, false);
                    cache.push(Node(item.x + dir.x, item.y + dir.y));
                }
            }
        }
        while (!cache.empty()) {
            jihoon.push(cache.front());
            cache.pop();
        }
    }

    if (found) {
        cout << turn;
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}