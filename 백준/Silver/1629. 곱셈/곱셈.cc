#include <iostream>

using namespace std;

long customPow(long base, long exp, long C) {
    if (exp == 0) {
        return 1;
    }
    if (exp % 2 == 1) {
        long r = base * customPow(base, exp-1, C);
        return r % C;
    }
    long r = customPow(base * base % C, exp/2, C);
    return r % C;
}

int main() {
    long A, B, C;
    cin >> A >> B >> C;

    cout << (customPow(A, B, C) % C);

    return 0;
}