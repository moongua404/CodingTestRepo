/*
개인마다
 - 위에 n명 밑에 m명이 있다면
 - n명에게 m명의 정보를 주고 m명에게 n명의 정보를 줌 
정보가 모두 공유된 후 나를 제외한 모든 이들의 정보를 알면 카운팅

브루트포스 - O(n^4)?
*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<unordered_set<int>> wins(n); // []가 이기는 사람들
    vector<unordered_set<int>> loses(n); // []가 지는 사람들
    
    for (vector<int> result : results) {
        wins[result[0]-1].insert(result[1]-1);
        loses[result[1]-1].insert(result[0]-1);
    }
    
    for (int _ = 0; _ < n; _++) {
        for (int i = 0; i < n; i++) {
            for (int loser : wins[i]) { // i에게 진 사람들은
                for (int winner : loses[i]) { // i를 이긴 모든 사람에 대해
                    loses[loser].insert(winner); // 진거나 마찬가지
                }
            }
            for (int winner : loses[i]) { // i에게 이긴 사람들은
                for (int loser : wins[i]) { // i에게 진 모든 사람에 대해
                    wins[winner].insert(loser); // 이긴거나 마찬가지
                }
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (wins[i].size() + loses[i].size() + 1 >= n) answer++;
    }
    return answer;
}