/*
공약수 갯수
5M까지면 어차피 5M 이상은 고려할 필요 없음
+ 탐색은 DP스럽게?
O(N log N)
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int e, vector<int> starts) {
    e += 1;
    vector<int> d(e); // [1] = 1
    for (int i = 1; i < e; i++) {
        for (int j = i; j < e; j += i) {
            d[j]++;
        }
    }
    
    vector<int> best(e+1);
    for (int i = e-1; i > 0; i--) {
        if (d[best[i+1]] <= d[i]) best[i] = i;
        else best[i] = best[i+1];
    }
    
    vector<int> answer;
    answer.reserve(starts.size());
    for (int v : starts) {
        answer.push_back(best[v]);
    }
    return answer;
}