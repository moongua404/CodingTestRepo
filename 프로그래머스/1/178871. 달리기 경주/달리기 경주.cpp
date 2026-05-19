/*
bruteforce?
핵심 병목 - 조회 (최악의 경우 1M번 50k의 요소를 search 해야함)

이름 - 숫자 / 숫자 - 이름 매핑해두고
이름으로 숫자를 조회, 숫자+1로 이름을 다시 조회
두 맵을 갱신

마지막에 숫자 맵을 full scan
*/

#include <string>
#include <vector>
#include <map>

using namespace std;

// players를 사용 및 변형
vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> nameMap;
    for (int i = 0; i < players.size(); i++) {
        nameMap.insert({players[i], i});
    }
    
    for (string name : callings) {
        int order = nameMap[name]; // 불일치하는 이름은 없다고 가정
        string headingName = players[order - 1]; // 항상 유효한 요청이라 가정 (선두가 있다고 가정)
        nameMap[name] = order - 1;
        nameMap[headingName] = order;
        players[order] = headingName;
        players[order - 1] = name;
    }
    
    return players;
}