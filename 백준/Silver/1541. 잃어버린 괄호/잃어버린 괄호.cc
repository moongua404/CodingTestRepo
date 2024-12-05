#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    queue<string> sq;
    cin >> s;

    while(true) {
        if (s.find('-') != string::npos) {
            sq.push(s.substr(0, s.find('-')));
            s = s.substr(s.find('-')+1, s.length());
            continue;
        }
        sq.push(s);
        break;
    }

    queue<int> iq;
    while(!sq.empty()) {
        string temp = sq.front();
        sq.pop();
        int val = 0;
        while(true) {
            if (temp.find('+') != string::npos) {
                val += stoi(temp.substr(0, temp.find('+')));
                temp = temp.substr(temp.find('+')+1, temp.length());
                continue;
            }
            val += stoi(temp.substr(0, temp.find('+')));
            break;
        }
        iq.push(val);
    }
    
    int sum = iq.front();
    iq.pop();
    while(!iq.empty()) {
        int val = iq.front();
        iq.pop();
        sum -= val;
    }
    
    cout << sum;
}