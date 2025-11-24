#include <iostream>
#include <queue>

using namespace std;

enum CellType {
    VOID, WALL
};

class Pos {
public:
    int x, y;
    Pos(int x, int y) : x(x), y(y) { }
};

class VirusMap {
    int N, M;
    CellType** map;
    queue<Pos> q;
    VirusMap() { }
public:
    VirusMap(int N, int M, int** map) {
        this->N = N;
        this->M = M;
        this->map = new CellType*[N];
        for (int i=0; i<N; i++) {
            this->map[i] = new CellType[M];
            for (int j=0; j<M; j++) {
                if (map[i][j] == 0) {
                    this->map[i][j] = VOID;
                    continue;
                }
                this->map[i][j] = WALL;
                if (map[i][j] == 2) {
                    q.push(Pos(i, j));
                }
            }
        }
    }

    VirusMap clone() {
        VirusMap other;
        other.N = this->N;
        other.M = this->M;

        other.map = new CellType*[N];
        for (int i = 0; i < N; i++) {
            other.map[i] = new CellType[M];
            for (int j = 0; j < M; j++) {
                other.map[i][j] = this->map[i][j];
            }
        }

        int qSize = this->q.size();
        for (int i = 0; i < qSize; i++) {
            Pos popped = this->q.front();
            this->q.pop();
            this->q.push(popped);
            other.q.push(popped);
        }
        return other;
    }

    bool putWall(Pos pos) {
        if (map[pos.x][pos.y] == WALL) {
            return false;
        }
        map[pos.x][pos.y] = WALL;
        return true;
    }

    void spreadVirus() {
        while(!q.empty()) {
            Pos virus = q.front();
            q.pop();
            if (virus.x > 0 && map[virus.x-1][virus.y] == VOID) {
                map[virus.x-1][virus.y] = WALL;
                q.push(Pos(virus.x-1, virus.y));
            }
            if (virus.x < N-1 && map[virus.x+1][virus.y] == VOID) {
                map[virus.x+1][virus.y] = WALL;
                q.push(Pos(virus.x+1, virus.y));
            }
            if (virus.y > 0 && map[virus.x][virus.y-1] == VOID) {
                map[virus.x][virus.y-1] = WALL;
                q.push(Pos(virus.x, virus.y-1));
            }
            if (virus.y < M-1 && map[virus.x][virus.y+1] == VOID) {
                map[virus.x][virus.y+1] = WALL;
                q.push(Pos(virus.x, virus.y+1));
            }
        }
    }

    int countSafeArea() {
        int count = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] == VOID) {
                    count++;
                }
            }
        }
        return count;
    }
};

void solution() {
    int N, M;
    cin >> N >> M;
    int** input = new int*[N];
    for (int i = 0; i < N; i++) {
        input[i] = new int[M];
        for (int j = 0; j < M; j++) {
            cin >> input[i][j];
        }
    }
    VirusMap virusMap(N, M, input);

    int max = 0;
    for (int x1 = 0; x1 < N; x1++) {
        for (int y1 = 0; y1 < M; y1++) {       
            for (int x2 = 0; x2 < N; x2++) {
                for (int y2 = 0; y2 < M; y2++) {
                    for (int x3 = 0; x3 < N; x3++) {
                        for (int y3 = 0; y3 < M; y3++) {
                            VirusMap other = virusMap.clone();
                            if (other.putWall(Pos(x1, y1)) && other.putWall(Pos(x2, y2)) && other.putWall(Pos(x3, y3))) {
                                other.spreadVirus();
                                int v = other.countSafeArea();
                                if (v > max) {
                                    max = v;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << max;
}

int main() {
    solution();

    return 0;
}