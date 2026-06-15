/*
a점수가 더 낮은 것 중 b점수가 더 높은게 있다면 끌어와서 씀. 
왜? 둘 중 하나라도 더 낮은 것을 집어야하니까. 
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    vector<int> limit(100001);
    for (vector<int>& score : scores) {
        if (limit[score[0]] < score[1]) {
            limit[score[0]] = score[1];
        }
    }
    int best = 0;
    for (int i = 100001; i >= 0; i--) {
        int t = best;
        if (best < limit[i]) best = limit[i];
        limit[i] = t;
    }
    
    vector<int> sumScore;
    sumScore.reserve(scores.size());
    for (vector<int> score : scores) {
        if (score[1] < limit[score[0]]) {
            sumScore.push_back(-1);
            continue;
        }
        sumScore.push_back(score[0] + score[1]);
    }
    
    if (sumScore[0] == -1) return -1;
    sort(sumScore.begin(), sumScore.end());
    
    int rOrder = lower_bound(sumScore.begin(), sumScore.end(), scores[0][0] + scores[0][1]+1) - sumScore.begin() - 1;
    return sumScore.size() - rOrder;
}