#include <iostream>

using namespace std;

void solution() {
    int tiger = 0, lion = 0;
    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        if (s == "Tiger") {
            tiger++;
            continue;
        }
        lion++;
    }

    cout << (tiger > lion ? "Tiger" : "Lion");
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();

    return 0;
}
