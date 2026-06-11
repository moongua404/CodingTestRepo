#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long parse(string s) {
    long long acc = 0;
    for (int i = 0; i < s.length(); i++) {
        acc *= 26;
        acc += (s[i] - 'a' + 1);
    }
    return acc;
}

// 1 a ... 26 z, 27 aa, 28 ab ...
string parse(long long n) {
    string s = "";
    while (n > 0) {
        n--;
        char c = (n%26 + 'a');
        s = c + s;
        n /= 26;
    }
    return s;
}


string solution(long long n, vector<string> bans) {
    vector<long long> longBan;
    longBan.reserve(bans.size());
    for (string& s : bans) longBan.push_back(parse(s));
    sort(longBan.begin(), longBan.end());
    for (long long v : longBan) {
        if (v <= n) n++;
    };
    
    return parse(n);
}