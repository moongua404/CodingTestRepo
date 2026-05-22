#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

class union_set {
    vector<int> head;
    
public:
    union_set(int size) {
        head.resize(size);
        for (int i = 0; i < size; i++) {
            head[i] = i;
        }
    }
    
    int find_root(int v) {
        if (head[v] == v) return v;
        head[v] = find_root(head[v]);
        return head[v];
    }
    
    bool unionWith(int a, int b) {
        if (find_root(a) == find_root(b)) return false;
        head[find_root(a)] = find_root(b);
        return true;
    }
};

int solution(vector<vector<int>> land, int height) {
    vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, 1} ,{0, -1}};
    int size = land.size(); // 정사각형
    union_set us(size * size);
    
    vector<pair<int, pair<int, int>>> routes; // <가격 <<x1, y1><x2, y2>>>
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (pair<int, int> dir : dirs) {
                int nx = i + dir.first;
                int ny = j + dir.second;
                if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                int cost = land[i][j] - land[nx][ny];
                    if (cost < 0) cost *= -1;
                    routes.push_back({cost, {i + j * size, nx + ny * size}});
            }
        }
    }
    
    sort(routes.begin(), routes.end(),
         [](auto& a, auto& b){
             return a.first < b.first;
         });
    
    int acc = 0;
    for (pair<int, pair<int, int>>& i : routes) {
        if (us.unionWith(i.second.first, i.second.second)) {
            if (i.first <= height) continue;
            acc += i.first;
        } 
    }
    return acc;
}