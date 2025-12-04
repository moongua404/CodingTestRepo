#include <iostream>

using namespace std;

bool isValid(string s) {
    int xCount = 0, oCount = 0;
    for (char ch : s) {
        if (ch == 'X') xCount++;
        else if (ch == 'O') oCount++;
    }
    if (xCount != oCount && xCount != oCount+1) {
        return false;
    }

    int rows = 0, cols = 0, dia = 0;
    int x=0, o=0;

    for (int i = 0; i < 3; i++) {
        if (s[i*3] != '.' && s[i*3] == s[i*3 + 1] && s[i*3] == s[i*3 + 2]) {
            rows++;
            if (s[i*3] == 'X') x++;
            else o++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (s[i] != '.' && s[i] == s[i+3] && s[i] == s[i+6]) {
            cols++;
            if (s[i] == 'X') x++;
            else o++;
        }
    }

    if (s[0] != '.' && s[0] == s[4] && s[0] == s[8]) {
        dia++;
        if (s[0] == 'X') x++;
        else o++;
    }
    if (s[2] != '.' && s[2] == s[4] && s[2] == s[6]) {
        dia++;
        if (s[2] == 'X') x++;
            else o++;
    }

    if (rows == 2 || cols == 2) return false;
    if (o > 0 && xCount > oCount) return false;
    if (x > 0 && xCount == oCount) return false;
    if (xCount + oCount != 9 && rows == 0 && cols == 0 && dia == 0) return false;
    return true;
}

void solution() {
    string s = "";
    while (true) {
        cin >> s;
        if (s == "end") {
            break;
        }
        cout << (isValid(s) ? "valid\n" : "invalid\n");
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();
    return 0;
}