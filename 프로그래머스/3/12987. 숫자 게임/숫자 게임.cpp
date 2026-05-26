/*
greedy 하게?
A랑 B 모두 sort해. 
A를 이길 수 있으면 +1 & A B 모두 pop / 없으면 A만 pop
-> O(n)
*/

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int SIZE = A.size();
    
    sort(A.begin(), A.end(), [](int a, int b){return a > b;});
    sort(B.begin(), B.end(), [](int a, int b){return a > b;});
    
    int BIter = 0;
    for (int i = 0; i < SIZE; i++) {
        if (A[i] < B[BIter]) {
            BIter++;
        }
    }
    
    return BIter;
}