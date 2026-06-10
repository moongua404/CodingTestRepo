/*
mem : 2^20 = 1,000,000
2000 * 20
*/

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers, int target) {
    vector<int> arr(2001);
    arr[1000] = 1;
    for (int number : numbers) {
        vector<int> temp(2001);
        for (int i = 0; i < 2001; i++) {
            if (arr[i] == 0) continue;
            // 범위 내 메모리 안터짐
            temp[i+number] += arr[i];
            temp[i-number] += arr[i];
        }
        arr = temp;
    }
    
    return arr[1000 + target];
}