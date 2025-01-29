#include <iostream>
using namespace std;

int sk[20000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        sk[n + 10000000]++;
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int v;
        cin >> v;
        cout << sk[v + 10000000] << ' ';
    }
}