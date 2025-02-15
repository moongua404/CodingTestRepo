#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, N;
    cin >> M >> N;

    bool* map = new bool[N];
    for (int i = 0; i < N; i++) {
        map[i] = true;
    }
    
    for (int i = 2; i <= N; i++) {
        if (map[i-1]) {
            if (i >= M) {
                cout << i << '\n';
            }
            for (int j = i; j <= N; j += i) {
                map[j-1] = false;
            }
        }
    }


    return 0;
}