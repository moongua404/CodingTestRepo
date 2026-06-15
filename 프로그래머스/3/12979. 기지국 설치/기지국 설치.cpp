/*
그리디 하게?
station-W부터 station+W까지는 설치할 필요 없음
K...Q의 범위에서 설치하는 비용은
    CEIL((Q-K)/(2W+1))

*/

#include <vector>
using namespace std;

int calcCost(int s, int e, int w) {
    // CEIL((End-Start)/(2*Width+1))
    int v = (e-s+2*w) / (2*w+1);
    if (v < 0) v = 0;
    return v;
}

int solution(int n, vector<int> stations, int w) {
    int acc = 0, start = 1;
    for (int dest : stations) {
        acc += calcCost(start, dest-w, w);
        start = dest+w+1;
    }
    acc += calcCost(start, n+1, w);
    return acc;
}