#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int five = 0, three = 0;
    int N;
    cin >> N;

    five = N/5;
    bool suc = false;

    while(five >= 0) {
        int v = five * 5 + three * 3;
        if (v == N) {
            suc = true;
            break;
        } else if (v < N) {
            three++;
        } else {
            five--;
        }
    }

    if (suc) {
        cout << five + three;
    } else {
        cout << -1;
    }

    return 0;
}