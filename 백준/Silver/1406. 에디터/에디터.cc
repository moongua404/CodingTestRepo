#include <iostream>
#include <list>

using namespace std;

void solution() {
    list<char> str;
    
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        str.push_back(s[i]);
    }

    auto iter = str.end();

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        char ch;
        cin >> ch;
        
        if (ch == 'L') {
            if (iter != str.begin()) {
                iter--;
            }
        }
        else if (ch == 'D') {
            if (iter != str.end()) {
                iter++;
            }
        }
        else if (ch == 'B') {
            if (iter != str.begin()) {
                iter = str.erase(--iter);
            }
        }
        else if (ch == 'P') {
            char v;
            cin >> v;
            str.insert(iter, v);
        }
    }

    for (char ch : str) {
        cout << ch;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();
    return 0;
}