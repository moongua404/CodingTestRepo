#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int N = stoi(s);
    int result = 0;

    for (int i = N - s.length() * 10; i < N; i++) {
        int sum = i;
        for (int j = 0; j < s.length(); j++) {
            sum += int(i / pow(10, j)) % 10;
        }
        if (N == sum) {
            result = i;
            break;
        }
    }
    cout << result;

    return 0;
}