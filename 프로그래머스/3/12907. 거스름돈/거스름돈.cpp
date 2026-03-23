/*
모든 화폐에 대해
남아있는 가격으로 구성할 수 있는 모든 경우의수를 따짐
*/

#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> money) {
    int* left = new int[n+1];
    for (int i = 0; i < n+1; i++) {
        left[i] = 0;
    }
    left[n] = 1; // 0 0 0 0 0 1
    
    for (int unit : money) {
        for (int i = 0; i < n+1; i++) {
            if (left[i] == 0) continue;
            for (int j = i - unit; j >= 0; j -= unit) {
                left[j] += left[i];
            }
        }
    }
    
    for (int i = 0; i < n+1; i++) {
        left[i] %= 1000000007;
    }
    
    return left[0];
}