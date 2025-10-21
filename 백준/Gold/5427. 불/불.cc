#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    for (int cnt = 0; cnt < N; cnt++) {
        int height, width;
        cin >> width >> height;

        bool** map = new bool*[height];//map[height][width]
        for (int i = 0; i < height; i++) {
            map[i] = new bool[width];
        }
        queue<pair<int, int> > loc;
        queue<pair<int, int> > fire;
        queue<pair<int, int> > temp;

        for (int i = 0; i < height; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < width; j++) {
                if (s[j] == '@') {
                    loc.push(make_pair(i, j));
                    map[i][j] = 1;
                } else if (s[j] == '*') {
                    fire.push(make_pair(i, j));
                    map[i][j] = 1;
                } else if (s[j] == '#') {
                    map[i][j] = 1;
                } else {
                    map[i][j] = 0;
                }
            }
        }

        int turn = 0;
        bool win = false;
        while(!loc.empty()) {
            turn++;

            while(!fire.empty()) {
                pair<int, int> v = fire.front();
                fire.pop();

                if (v.first < height - 1 && !map[v.first+1][v.second]) {
                    temp.push(make_pair(v.first+1, v.second));
                    map[v.first+1][v.second] = 1;
                }
                if (v.first > 0 && !map[v.first-1][v.second]) {
                    temp.push(make_pair(v.first-1, v.second));
                    map[v.first-1][v.second] = 1;
                }
                if (v.second < width + 1 && !map[v.first][v.second+1]) {
                    temp.push(make_pair(v.first, v.second+1));
                    map[v.first][v.second+1] = 1;
                }
                if (v.second > 0 && !map[v.first][v.second-1]) {
                    temp.push(make_pair(v.first, v.second-1));
                    map[v.first][v.second-1] = 1;
                }
            }
            while(!temp.empty()) {
                fire.push(make_pair(temp.front().first, temp.front().second));
                temp.pop();
            }
            
            while(!loc.empty()) {
                pair<int, int> v = loc.front();
                loc.pop();
                
                //벽에 붙어있으면 turn++, win
                if (v.first == 0 || v.second == 0 || v.first == height - 1 || v.second == width - 1) {
                    win = true; break;
                }

                //사람을 움직여
                if (v.first < height - 1 && !map[v.first+1][v.second]) {
                    temp.push(make_pair(v.first+1, v.second));
                    map[v.first+1][v.second] = 1;
                }
                if (v.first > 0 && !map[v.first-1][v.second]) {
                    temp.push(make_pair(v.first-1, v.second));
                    map[v.first-1][v.second] = 1;
                }
                if (v.second < width + 1 && !map[v.first][v.second+1]) {
                    temp.push(make_pair(v.first, v.second+1));
                    map[v.first][v.second+1] = 1;
                }
                if (v.second > 0 && !map[v.first][v.second-1]) {
                    temp.push(make_pair(v.first, v.second-1));
                    map[v.first][v.second-1] = 1;
                }
            }
            if (win) { break; }
            while(!temp.empty()) {
                loc.push(make_pair(temp.front().first, temp.front().second));
                temp.pop();
            }
        }

        if (win) {
            cout << turn << '\n';
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
}