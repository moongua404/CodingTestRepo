/*
0이 된다는게 중요한건 아님 -> 그냥 threshold를 늘리며 이것보다 큰가를 계산
    -> 이진탐색
O(n * m) -> O(n log m)
*/

#include <string>
#include <vector>

using namespace std;

bool isAble(vector<int>& stones, int k, int threshold) {
    int i = 0;
    int jump = 0;
    while(i < stones.size()) {
        if (stones[i] < threshold) {
            jump++;
            if (jump >= k) return false;
        } else {
            jump = 0;
        }
        i++;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int min = 0; // 가능한 하한
    int max = 200000001; // 불가능한 상한
    
    while(min+1 < max) {
        int mid = (min + max) / 2; // worst 4억 정도 -> OK
        if (isAble(stones, k, mid)) {
            min = mid;
        } else {
            max = mid;
        }
    }
    
    return min;
}