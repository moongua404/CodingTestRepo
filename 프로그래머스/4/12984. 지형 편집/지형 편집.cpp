/*
평탄화
max(N) = 300

이진탐색 -> O(n^2 log n)
최소값을 기준으로 항상 하강, 상승하는 임의의 함수 f(x)에 대해,
    임의의 두 점 x1, x2 사이에 최소값이 있다면
    그 사이에 있는 두 점 x3, x4이 x3 > x4를 만족할 때,
        f(x3)가 f(x4)보다 작으면 최소한 x3와 x2 사이에 최소값이 있음
        반대로 f(x4)가 f(x3)보다 작으면 최소한 x4와 x1 사이에 최소값이 있음
*/

#include <vector>
#include <unordered_map>

using namespace std;

long long calcPrice(vector<int>& heights, long t, int P, int Q) {
    long long plus = 0;
    long long minus = 0;
    for (int h : heights) {
        if (h < t) plus += (t-h);
        else minus += (h-t);
    }
    return plus * P + minus * Q;
}

long long solution(vector<vector<int>> land, int P, int Q) {
    int size = land.size();
    int minV = 0, maxV = 1000000000;
    vector<int> heights;
    heights.reserve(size * size);
    for (vector<int>& line : land) {
        for (int& spot : line) {
            heights.push_back(spot);
        }
    }
    
    pair<int, long long> lower = {minV, calcPrice(heights, minV, P, Q)};
    pair<int, long long> upper = {maxV, calcPrice(heights, maxV, P, Q)};
    
    while(lower.first+2 < upper.first) {
        int t = (lower.first + upper.first) / 2;
        pair<int, long long> mid = {t, calcPrice(heights, t, P, Q)};
        pair<int, long long> mid2 = {t+1, calcPrice(heights, t+1, P, Q)};
        if (mid.second > mid2.second) {
            lower = mid;
        } else {
            upper = mid2;
        }
    }
    
    long long res = calcPrice(heights, upper.first, P, Q);
    for (int i = lower.first; i < upper.first; i++) {
        long long v = calcPrice(heights, i, P, Q);
        if (res > v) res = v;
    }
    
    return res;
}