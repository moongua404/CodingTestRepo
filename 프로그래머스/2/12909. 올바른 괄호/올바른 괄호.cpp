#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int idx = 0;
    
    for (char ch : s) {
        if (ch == '(') {
            idx++;
        } else if (ch == ')') {
            idx--;
        }
        
        if (idx < 0) {
            answer = false;
            break;
        }
    }
    if (idx != 0) {
        answer = false;
    }
    
    return answer;
}