#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int pos;
    bool visited;
    Node(int pos = 0, bool visited = false) : pos(pos), visited(visited) {}
};

class Horse {
public:
    int pos, turn;
    Horse(int pos = 0, int turn = 0) : pos(pos), turn(turn) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    Node blocks[100];
    queue<Horse> horses;
    int dices[6] = { 1, 2, 3, 4, 5, 6 };
    horses.push(0);

    for (int i = 0; i < N + M; i++) {
        int n, m;
        cin >> n >> m;
        blocks[n-1].pos = m-n;
    }
    
    while(true) {
        Horse horse = horses.front();
        
        if (horse.pos == 99) {
            break;
        } else if (horse.pos > 99 || horse.pos < 0) {
            horses.pop();
            continue;
        }

        horses.pop();

        for (int dice : dices) {
            if (horse.pos + dice <= 99 && !blocks[horse.pos + dice].visited) {
                blocks[horse.pos + dice].visited = true;
                int newPos = horse.pos + dice + blocks[horse.pos + dice].pos;
                while(newPos <= 99 && blocks[newPos].pos != 0) {
                    newPos += blocks[newPos].pos;
                }
                horses.push(Horse(newPos, horse.turn + 1));
            }
        }
    }

    cout << horses.front().turn;

    return 0;
}