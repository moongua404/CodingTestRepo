/*
임의의 위치 t에 대해 팰린드롬을 구하면?
*/

#include <string>
#include <vector>
using namespace std;

int calcScore(string& s, int left, int right) {
    int score = 0;
    if (left == right) score--;
    
    while(left >= 0 && right < s.length()) {
        if (s[left--] == s[right++]) {
            score += 2;
        } else {
            break;
        }
    }
    
    return score;
}

int solution(string s)
{
    int max = 0;
    for (int i = 0; i < s.length(); i++) {
        for (int j = 0; j < 2; j++) {
            if (i-j >= 0) {
                int v = calcScore(s, i-j, i);
                if (v > max) max = v;
            }
        }
    }
    return max;
}