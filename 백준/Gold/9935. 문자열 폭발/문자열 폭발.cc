#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<char> line, res;
    string target;

    char ch;
    while((ch = cin.get()) != '\n') {
        line.push(ch);
    }
    cin >> target;

    while(!line.empty()) {
        ch = line.top();
        line.pop();
        if (ch != target[0]) {
            res.push(ch);
        } else {
            stack<char> temp;
            bool hit = true;
            temp.push(ch);
            for (int i = 1; i < target.size(); i++) {
                if (!res.empty() && res.top() == target[i]) {
                    temp.push(res.top());
                    if (!res.empty()) {
                        res.pop();
                    }
                } else {
                    hit = false;
                    break;
                }
            }
            if (!hit) {
                while(!temp.empty()) {
                    res.push(temp.top());
                    temp.pop();
                }
            }
        }
    }

    if (res.size() == 0) {
        cout << "FRULA";
    }

    while (!res.empty()) {
        cout << res.top();
        res.pop();
    }

    return 0;
}
