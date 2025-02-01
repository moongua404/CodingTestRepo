#include <iostream>
using namespace std;

int invert(int v) {
    return ((v%10) * 100 + ((v%100)/10)*10 + (v/100));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int A, B;
    cin >> A >> B;

    A = invert(A);
    B = invert(B);

    cout << ((A > B) ? A : B);

    return 0;
}