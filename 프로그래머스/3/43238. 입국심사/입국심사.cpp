/*
언제 누가 어디에 들어갔는지는 관심사 밖. 
n초만에 심사를 받았다는 말은 어떤 값 v을 각각의 times로 나눈 값 만큼의 사람을 심사했다는 뜻
다시 말해, 처리한 사람이 목표보다 같거나 큰 v 중 가장 작은 v을 구해야 함

바이너리 서치
    - O (m log n)
    - worst ~= 100,000 * 60 * k
*/

#include <string>
#include <vector>

using namespace std;

bool isAble(vector<int>& times, unsigned long long time, long long customer) {
    long long cnt = 0;
    for (int t : times) {
        cnt += time / t;
    }
    return cnt >= customer;
}

long long solution(int n, vector<int> times) {
    long long min = 0, max = 1000000000LL * 1000000000LL;
    
    while(min+1 < max) {
        unsigned long long mid = (min + max) / 2;
        if (isAble(times, mid, n)) max = mid;
        else min = mid;
    }
    
    return max;
}