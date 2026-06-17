/*
DP
O(N * M^2)
N ~<= 100000, M ~<= 10
*/

#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<vector<int>> createCostBoard() {
    return {
      //{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
        {1, 7, 6, 7, 5, 4, 5, 3, 2, 3}, // 0
        {7, 1, 2, 4, 2, 3, 5, 4, 5, 6}, // 1
        {6, 2, 1, 2, 3, 2, 3, 5, 4, 5}, // 2
        {7, 4, 2, 1, 5, 3, 2, 6, 5, 4}, // 3
        {5, 2, 3, 5, 1, 2, 4, 2, 3, 5}, // 4
        {4, 3, 2, 3, 2, 1, 2, 3, 2, 3}, // 5
        {5, 5, 3, 2, 4, 2, 1, 5, 3, 2}, // 6
        {3, 4, 5, 6, 2, 3, 5, 1, 2, 4}, // 7
        {2, 5, 4, 5, 3, 2, 3, 2, 1, 2}, // 8
        {3, 6, 5, 4, 5, 3, 2, 4, 2, 1}  // 9
    };
}

int solution(string numbers) {
    int size = numbers.size();
    
    vector<vector<int>> costBoard = createCostBoard();
    
    // [i+1]번째를 집을 때 [왼손]과 [오른손]의 위치에서 비용
    vector<vector<vector<int>>> minCost
        (size+1, vector<vector<int>>(10, vector<int>(10, 0x7FFFFFFF)));
    minCost[0][4][6] = 0;
    
    for (int i = 0; i < size; i++) {
        int dest = numbers[i] - '0';
        for (int left = 0; left < 10; left++) { // 고정
            if (dest == left) continue;
            for (int right = 0; right < 10; right++) { // 에서
                int cost = minCost[i][left][right] + costBoard[right][dest];
                if (cost < 0) continue;
                if (minCost[i+1][left][dest] > cost) {
                    minCost[i+1][left][dest] = cost;
                }
            }
        }
        
        for (int right = 0; right < 10; right++) { // 고정
            if (dest == right) continue;
            for (int left = 0; left < 10; left++) { // 에서
                int cost = minCost[i][left][right] + costBoard[left][dest];
                if (cost < 0) continue;
                if (minCost[i+1][dest][right] > cost) {
                    minCost[i+1][dest][right] = cost;
                }
            }
        }
    }
    
    int answer = 0x7FFFFFFF;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (answer > minCost[size][i][j]) answer = minCost[size][i][j];
        }
    }
    return answer;
}