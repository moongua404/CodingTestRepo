#include <iostream>

using namespace std;

void solution() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << "YONSEI";
    }
    if (n == 1) {
        cout << "Leading the Way to the Future";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();
    return 0;
}
