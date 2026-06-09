/*
해시 -> 유사 투포인터
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    while(!completion.empty() && !participant.empty()) {
        if (completion.back() == participant.back()) {
            completion.pop_back();
            participant.pop_back();
            continue;
        }
        if (completion.back() > participant.back()) {
            return completion.back();
        }
        return participant.back();
    }
    
    if (participant.empty()) {
        return completion.back();
    }
    return participant.back();
    
    return "-500";
}