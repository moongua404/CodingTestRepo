// 단순 구현
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    vector<int> time(48, m-1);
    
    int acc = 0;
    for (int i = 0; i < players.size(); i++) {
        if (players[i] < m) continue;
        if (time[i] < players[i]) {
            int amt = (players[i] - time[i] + m - 1) / m;
            acc += amt;
            for (int j = 0; j < k; j++) time[i+j] += amt * m;
        }
    }
    return acc;
}