/*
~= 투포인터

k번째 요소 이전과 k+1번째 요소 이후로 선물을 주려 할 때
O(n^2)
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cookie) {
    int size = cookie.size();
    int max = 0;
    
    for (int k = 0; k < size - 1; k++) {
        int leftIter = k, rightIter = k+1;
        int leftSum = cookie[k], rightSum = cookie[k+1];
        while(true) {
            if (leftSum == rightSum && max < leftSum) max = leftSum;
            if (leftSum < rightSum) {
                leftIter--;
                if (leftIter < 0) break;
                leftSum += cookie[leftIter];
            } else {
                rightIter++;
                if (rightIter >= size) break;
                rightSum += cookie[rightIter];
            }
        }
    }
    
    return max;
}