#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> works) {
    int worksIdx = 0;
    
    // 큰거부터로 소트를 하고
    sort(works.begin(), works.end());
    reverse(works.begin(), works.end());
    
    // 큰거부터 뽑은 후 뺌
    long long biggest = works[0];
    long long biggestCnt = 0;
    
    while (true) {
        while(worksIdx < works.size() && works[worksIdx] == biggest) {
            biggestCnt++;
            worksIdx++;
        }
        if (worksIdx >= works.size()) break;
        long long gap = biggest - works[worksIdx];
        if (n < gap * biggestCnt) break;
        biggest -= gap;
        n -= gap * biggestCnt;
    }
    // n을 뺄 수 있는 만큼 빼야 함
    long long gap = n / biggestCnt;
    if (gap > 0) {
        biggest -= gap;
        n -= gap * biggestCnt;
    }
    if (biggest <= 0) return 0;
    
    long long answer = 0;
    // 잔챙이 n을 취급
    answer += (biggest-1) * (biggest-1) * n;
    biggestCnt -= n;
    answer += biggest * biggest * biggestCnt;
    //나머지
    for (int i = worksIdx; i < works.size(); i++) {
        answer += works[i] * works[i];
    }
    return answer;
}