#include <iostream>

using namespace std;

void solution() {
    int T, W;
    cin >> T >> W;
    W++;

    int a[W], b[W];
    for (int i = 0; i < W; i++) {
        a[i] = 0; b[i] = 0;
    }

    for (int i = 0; i < T; i++) {
        int v;
        cin >> v;

        if (v == 1) {
            for (int j = 0; j < W; j++) a[j]++;
            
            for (int j = 1; j < W-1; j++) {
                if (b[j] + 1 > a[j+1]) {
                    a[j+1] = b[j]+1;
                }
            }
        }
        else if (v == 2) {
            for (int j = 0; j < W; j++) b[j]++;
            for (int j = 0; j < W-1; j++) {
                if (a[j] + 1 > b[j+1]) {
                    b[j+1] = a[j] + 1;
                }
            }
        }
    }

    int best = (a[W-1] > b[W-1] ? a[W-1] : b[W-1]);
    cout << best;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();
    return 0;
}
