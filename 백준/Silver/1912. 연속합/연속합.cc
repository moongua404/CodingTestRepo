#include <iostream>

using namespace std;

void solution() {
    /* greedy */    
    int n;
    cin >> n;

    int max = 0x80000000, acc = 0;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        acc += v;
        if (acc > max) {
            max = acc;
        }
        if (acc <= 0) {
            acc = 0;
            continue;
        }
    }

    cout << max;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();

    return 0;
}
