#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    string s;

    cin >> N >> M >> s;
    
    int count = 0, status = 0;

    for (int i = 0; i < M; i++) {
        if (s[i] == 'I') {
            if (status%2 == 0) {
                status++;
                if (status == 2*N+1) {
                    count++;
                    status -= 2;
                }
            } else {
                status = 1;
            }
        } else if (s[i] == 'O' && status%2 == 1) {
            status++;
        } else {
            status = 0;
        }
    }
    cout << count;
}