#include <iostream>
#include <algorithm>
using namespace std;

bool cpr(string s1, string s2) {
    if (s1.length() == s2.length()) {
        return s1 < s2;
    }
    return s1.length() < s2.length();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string* s = new string[N];

    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    sort(s, s+N, cpr);

    string before = "\0";
    for (int i = 0; i < N; i++) {
        if (s[i] != before) {
            cout << s[i] << "\n";
        }
        before = s[i];
    }
}
