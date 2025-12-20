#include <iostream>

using namespace std;

void solution() {
    string s;
    while (getline(cin, s)) {
        if (s.empty()) continue;

        int pivot = s.find(' ');

        int N = stoi(s.substr(0, pivot));
        int S = stoi(s.substr(pivot + 1));

        cout << S / (N + 1) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();
    return 0;
}
