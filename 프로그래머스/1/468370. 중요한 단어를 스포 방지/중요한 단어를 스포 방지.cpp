/*
중요 단어 조건
 - 스포 방지 걸려있어야 함
 - 아닌 구간에 없어야 함
 - 중복되지 않아야 함

메시지 -> 단어들 -> 숨겨진 단어들 / 아닌 단어들
아닌 단어들로 먼저 단어장을 구성 (블랙리스트)
숨겨진 단어들로 단어장을 구성 (후보군)
후보군에서 블랙리스트를 무효화
후보군을 순회하며 살아남은 단어의 갯수를 카운트
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges) {
    bool* mask = new bool[message.length()];
    for (int i = 0; i < message.length(); i++) {
        mask[i] = false;
    }
    for (vector<int> range : spoiler_ranges) {
        for (int i = range[0]; i <= range[1]; i++) {
            mask[i] = true;
        }
    }
    
    set<string> blacklist;
    set<string> candidates;
    
    string word = "";
    bool flag = false;
    for (int i = 0; i < message.length(); i++) {
        if (message[i] == ' ') {            
            (flag) ? candidates.insert(word) : blacklist.insert(word);
            word = "";
            flag = false;
            continue;
        }
        if (!flag && mask[i]) flag = true;
        word += message[i];
    }
    (flag) ? candidates.insert(word) : blacklist.insert(word);
    
    for (string s : blacklist) {
        candidates.erase(s);
    }
    
    int answer = candidates.size();
    return answer;
}