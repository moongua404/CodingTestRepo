/*
제일 긴 루프를 기준으로 맞는지 확인?
실패하면 -1
*/

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> signals) {
    int size = signals.size();
    
    int* totalLoop = new int[size];
    for (int i = 0; i < size; i++) {
        totalLoop[i] = signals[i][0]+signals[i][1]+signals[i][2];
    }
    
    int maxIdx = 0;
    for (int i = 1; i < size; i++) {
        if (totalLoop[i] > totalLoop[maxIdx]) {
            maxIdx = i;
        }
    }
    
    int acc = 0;
    while (acc >= 0) {
        acc += signals[maxIdx][0];
        
        for (int k = 0; k < signals[maxIdx][1]; k++) {
            acc++;
            bool flag = true;
            for (int i = 0; i < size; i++) {
                int yellowEnter = acc % totalLoop[i] - signals[i][0];
                if (yellowEnter > 0 && yellowEnter <= signals[i][1]) {
                    continue;
                }
                flag = false;
                break;
            }
            if (flag) {
                return acc;
            }
        }
        
        acc += signals[maxIdx][2];
    }
    
    return -1;
}