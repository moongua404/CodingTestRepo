#include <string>
#include <vector>

using namespace std;

class num {
public:
    int v;
    bool isInfinite;
    
    num(int v) : v(v), isInfinite(false) { }
    num() : v(0), isInfinite(true) { }
    num operator+(const num& other) const {
        if (isInfinite || other.isInfinite) {
            return num();
        }
        return num(v + other.v);
    }
    
    bool operator<(const num& other) const {
        if (isInfinite) { return false; }
        if (other.isInfinite) { return true; }
        return v < other.v;
    }
};

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    s--; a--; b--;
    
    vector<vector<num>> costMap;
    for (int i = 0; i < n; i++) {
        costMap.push_back(vector<num>());
        for (int j = 0; j < n; j++) {
            costMap[i].push_back((i == j) ? num(0) : num());
        }
    }
    
    for (vector<int> fare : fares) {
        costMap[fare[0]-1][fare[1]-1] = num(fare[2]);
        costMap[fare[1]-1][fare[0]-1] = num(fare[2]);
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                num newCost = costMap[i][k] + costMap[k][j];
                if (newCost < costMap[i][j]) {
                    costMap[i][j] = newCost;
                }
            }
        }
    }
    
    num min(200 * 199 / 2 * 100000 + 1);
    
    for (int share = 0; share < n; share++) {
        num v = costMap[s][share] + costMap[share][a] + costMap[share][b];
        if (v < min) { min = v; }
    }
    
    return min.v;
}