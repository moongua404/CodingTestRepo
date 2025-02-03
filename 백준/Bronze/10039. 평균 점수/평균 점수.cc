#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n[5];

    for (int i = 0; i < 5; i++) {
        cin >> n[i];
    }

    int sum = 0;

    for (int i = 0; i < 5; i++) {
        if (n[i] < 40) {
            sum += 40;
        } else {
            sum += n[i];
        }
    }
    
    cout << sum / 5;

    return 0;
}