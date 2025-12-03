#include <iostream>
#include <set>

using namespace std;

void solution() {
    int N;
    set<string> ingredients;

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        ingredients.insert(s);
    }
    for (int i = 0; i < N-1; i++) {
        string s;
        cin >> s;
        ingredients.erase(s);
    }
    cout << *ingredients.begin();
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();

    return 0;
}
