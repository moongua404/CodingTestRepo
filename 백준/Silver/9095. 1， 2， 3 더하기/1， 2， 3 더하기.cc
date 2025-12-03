#include <iostream>

using namespace std;

void testCase() {
    static int answer[10] = {1, 2, 4, 7, 13, 24, 44, 81, 149, 274};
    int n;
    cin >> n;
    cout << answer[n-1] << '\n';
}

void solution() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        testCase();
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();

    return 0;
}
