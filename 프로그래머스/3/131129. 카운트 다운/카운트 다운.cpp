/*
dp
121 * 100,000
*/

#include <string>
#include <vector>

using namespace std;

bool isLessThan(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

pair<int, int> add(pair<int, int> base, int f, int s) {
    return {base.first + f, base.second + s};
}

vector<int> solution(int target) {
    vector<pair<int, int>> v(target+1); // []를 만들 때 최소의 비용
    
    for (int i = 1; i <= target; i++) {
        pair<int, int> min = {0x7FFFFFFF, 0x7FFFFFFF};
        
        for (int j = i-20; j < i; j++) {
            if (j < 0) continue;
            pair<int, int> c = add(v[j], 1, 1);
            if (isLessThan(c, min)) min = c;
        }
        for (int j = i-40; j < i; j += 2) {
            if (j < 0) continue;
            pair<int, int> c = add(v[j], 1, 0);
            if (isLessThan(c, min)) min = c;
        }
        for (int j = i-60; j < i; j += 3) {
            if (j < 0) continue;
            pair<int, int> c = add(v[j], 1, 0);
            if (isLessThan(c, min)) min = c;
        }
        if (i-50 >= 0) {
            pair<int, int> c = add(v[i-50], 1, 1);
            if (isLessThan(c, min)) min = c;
        }        
        v[i] = min;
    }
    
    return {v[target].first, v[target].second};
}