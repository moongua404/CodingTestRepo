/*
DP
위치별로 n번째 중 중 m개를 맞췄을 때
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    // []번째 노드에서, []번째 로그 까지 중에 최대 맞는 갯수 - [0]은 dummy
    vector<vector<int>> table(n+1, vector<int>(k+1));
    for (vector<int>& line : table) {
        for (int& v : line) {
            v = -1;
        }
    }
    table[gps_log[0]][1] = 1;
    
    unordered_map<int, unordered_set<int>> routes;
    for (vector<int> edge : edge_list) {
        routes[edge[0]].insert(edge[1]);
        routes[edge[1]].insert(edge[0]);
    }
    for (int logIdx = 2; logIdx <= /*gps size*/ k; logIdx++) {
        for (int nodeIdx = 1; nodeIdx <= /*node size*/ n; nodeIdx++) {
            int localMax = table[nodeIdx][logIdx-1];
            for (int adj : routes[nodeIdx]) {
                if (table[adj][logIdx-1] > localMax) {
                    localMax = table[adj][logIdx-1];
                }
            }
            if (localMax != -1 && gps_log[logIdx-1] == nodeIdx) localMax++;
            table[nodeIdx][logIdx] = localMax;
        }
    }
    
    if (table[gps_log[k-1]][k] == -1) return -1;
    return k - table[gps_log[k-1]][k];
}