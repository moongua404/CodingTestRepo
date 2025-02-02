#include <iostream>
using namespace std;

class Map {
public:
    bool map[26];
    Map() {
        for (int i = 0; i < 26; i++) {
            map[i] = false;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, count = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        Map map;
        char pre = ' ';
        bool flag = true;

        for (int j = 0; j < s.length(); j++) {
            if (pre != s[j]) {
                pre = s[j];
                if (map.map[int(s[j])-97]) {
                    flag = false;
                    break;
                } else {
                    map.map[int(s[j]-97)] = true;
                }
            }
        }

        count += flag;
    }
    cout << count;

    return 0;
}