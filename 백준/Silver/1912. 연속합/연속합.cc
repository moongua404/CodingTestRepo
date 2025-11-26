#include <iostream>
#include <vector>

using namespace std;

void solution() {
    /* greedy */    
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int max = 0x80000000, acc = 0;
    for (int i = n-1; i >= 0; i--) {
        acc += v[i];
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
