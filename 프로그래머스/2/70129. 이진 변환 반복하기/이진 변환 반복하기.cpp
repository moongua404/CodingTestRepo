#include <string>
#include <vector>

using namespace std;

string toBinary(int v) {
    string s = "1";
    while(v != 1) {
        s += (v % 2 == 0) ? '0' : '1';
        v /= 2;
    }
    return s;
}

pair<int, string> t12n(string s) {
    int c = 0;
    for (char ch : s) {
        if (ch == '1') c++;
    }
    return {s.length()-c, toBinary(c)};
}

vector<int> solution(string s) {
    int cnt = 0, acc = 0;
    while(s != "1") {
        pair<int, string> r = t12n(s);
        cnt++;
        acc += r.first;
        s = r.second;
    }
    
    return {cnt, acc};
}