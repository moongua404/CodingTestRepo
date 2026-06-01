/*
거꾸로 strs로 셋을 만들어두고 t를 통해 재귀적으로 탐색?
    재귀->DP (n자까지 최소 단어 수)
*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<string> strs, string t) {
    int MAX_INT = 0x7FFFFFFF;
    
    int maxSize = 0;
    unordered_set<string> strSet;
    vector<int> cases(t.length()+1);
    
    for (string s : strs) {
        strSet.insert(s);
        if (s.length() > maxSize) maxSize = s.length();
    }
    
    cases[0] = 0;
    for (int i = 1; i < cases.size(); i++) {
        cases[i] = MAX_INT;
    }
    
    for (int i = 1; i <= t.length(); i++) { // i-1 번째까지 경우의 수
        for (int j = 1; j <= maxSize; j++) {
            if (i-j >= 0
                && strSet.find(t.substr(i-j, j)) != strSet.end()
                && cases[i-j] != MAX_INT) {
                if (cases[i] > cases[i-j]+1) cases[i] = cases[i-j]+1;
            }
        }
    }
    
    if (cases[t.length()] == MAX_INT) return -1;
    return cases[t.length()];
}