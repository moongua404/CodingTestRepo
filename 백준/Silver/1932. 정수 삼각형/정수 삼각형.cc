#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    int* pre = new int[N];
    int* post = new int[N];

    cin >> pre[0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i+1; j++) {
            int v, left = 0, right = 0;
            cin >> v;
            
            if (j != 0) {
                left = v + pre[j-1];
            }
            if (j != i) {
                right = v + pre[j];
            }
            post[j] = (left > right) ? left : right;
        }
        for (int j = 0; j < i+1; j++) {
            pre[j] = post[j];
        }
    }

    int max = 0;
    for (int i = 0; i < N; i++) {
        if (pre[i] > max) {
            max = pre[i];
        }
    }
    cout << max;

    return 0;
}
