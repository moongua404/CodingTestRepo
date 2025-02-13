#include <iostream>
#include <algorithm>
using namespace std;

class Position {
public:
    int x, y;
    Position(int x = 0, int y = 0) : x(x), y(y) {}
    static bool compare(Position one, Position other) {
        if (one.y == other.y) {
            return one.x < other.x;
        }
        return one.y < other.y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    Position* poses = new Position[N];
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        poses[i] = Position(x, y);
    }

    sort(poses, poses+N, Position::compare);

    for (int i = 0; i < N; i++) {
        cout << poses[i].x << ' ' << poses[i].y << '\n';
    }

    return 0;
}