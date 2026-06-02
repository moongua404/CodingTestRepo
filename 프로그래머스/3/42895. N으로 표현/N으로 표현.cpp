/*
n -> + - * / |

DP 스럽게
*/

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

enum Operation {
    PLUS, MINUS, TIMES, DIVIDE
};

pair<bool, int> calculate(Operation op, int v, int n) {
    if (op == PLUS) return {true, v + n};
    if (op == MINUS) return {true, v - n};
    if (op == TIMES) return {true, v * n};
    if (op == DIVIDE) {
        if (n == 0) return {false, -500};
        return {true, v / n};
     };
    return {false, -500}; // 도달할 수 없음
}

int solution(int N, int number) {
    vector<Operation> operations{
        PLUS, MINUS, TIMES, DIVIDE
    };
    
    vector<unordered_set<int>> vec(9);
    for (int i = 0; i < 9; i++) {
        int t = 0;
        for (int j = 0; j <= i; j++) {
            t *= 10;
            t += N;
        }
        vec[i].insert(t);
    }
    
    for (int i = 1; i <= 8; i++) {
        if (vec[i-1].find(number) != vec[i].end()) return i;
        for (int j = 1; j < i; j++) {
            for (int v1 : vec[j-1]) { // outer
                for (int v2 : vec[i-j-1]) { // inner
                    for (Operation op : operations) {
                        pair<bool, int> res = calculate(op, v1, v2);
                        if (!res.first) continue;
                        int v = res.second;
                        if (v <= 0) continue;
                        vec[i-1].insert(v);
                        if (v == number) return i;
                    }
                }
            }
        }
    }
    
    return -1;
}