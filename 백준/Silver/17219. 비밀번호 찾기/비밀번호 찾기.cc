#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    map<string, string> secrets;

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        secrets[s1] = s2;
    }
    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        cout << secrets[s] << '\n';
    }

    return 0;
}