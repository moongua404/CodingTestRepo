/*
(조금 greedy한) 단순 탐색

+에서 시작, sum이 양수인 동안 최대를 갱신

끝나면 배열 모두를 -1 곱해서 다시. 
*/

#include <string>
#include <vector>

using namespace std;

int pulse(int v) {
    return (v % 2 == 0) ? 1 : -1;
}

long long solution(vector<int> sequence) {
    int size = sequence.size();
    for (int i = 1; i < size; i+=2) {
        sequence[i] *= -1; // make pulse
    }
    
    long long max = 0;
    for (int i = 0; i < size; i++) {
        if (sequence[i] <= 0) continue;
        long long tempSum = 0;
        for (int j = i; j < size; j++) {
            i = j;
            tempSum += sequence[i];
            if (tempSum <= 0) break;
            if (tempSum > max) max = tempSum;
        }
    }
    
    for (int i = 0; i < size; i++) {
        sequence[i] *= -1;
    }
    for (int i = 0; i < size; i++) {
        if (sequence[i] <= 0) continue;
        long long tempSum = 0;
        for (int j = i; j < size; j++) {
            i = j;
            tempSum += sequence[i];
            if (tempSum <= 0) break;
            if (tempSum > max) max = tempSum;
        }
    }
    
    return max;
}