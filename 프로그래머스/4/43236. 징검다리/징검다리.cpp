/*
임의의 최소값 후보 k에 대해 이진 탐색

dist를 구해 둠
후보 k에 대해
    dist를 순회하며 k보다 작은 값이 있으면
        거리를 뒷 노드에게 이월, 카운트
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int breakCount(vector<int>& vec, int threshold) {
    int cnt = 0, passV = 0;
    for (int& v : vec) {
        if (v + passV >= threshold) {
            passV = 0;
            continue;
        }
        cnt++;
        passV += v;
    }
    return cnt;
}

// vector should be sorted
vector<int> getDistances(vector<int>& nodes, int end) {
    vector<int> res(nodes.size()+1);
    
    res[0] = nodes[0];
    for (int i = 0; i < nodes.size() - 1; i++) {
        res[i+1] = nodes[i+1] - nodes[i];
    }
    res[nodes.size()] = end - nodes[nodes.size()-1];
    
    return res;
}

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(), rocks.end());
    vector<int> dists = getDistances(rocks, distance);
    
    int lower = 0, upper = 1000000001; // min is OK, max is not. 
    while(lower+1 < upper) {
        int mid = (lower + upper) / 2; // no overflow
        if (breakCount(dists, mid) <= n) lower = mid;
        else upper = mid;
    }
    return lower;
}