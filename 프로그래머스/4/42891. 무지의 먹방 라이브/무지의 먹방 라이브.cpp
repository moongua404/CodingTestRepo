/*
이진 탐색
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// min is availabe, max is not
long long getThreshold(vector<int> times, long long limit) {
    sort(times.begin(), times.end());
    long long min = 0, max = 100000001; // 하드코딩
    while(min + 1 < max) {
        long mid = (min + max) / 2;
        long long acc = 0;
        for (int time : times) {
            if (time > mid) acc += mid;
            else acc += time;
            if (acc >= limit) break;
        }
        if (acc >= limit) max = mid;
        else min = mid;
    }
    return min;
}

int solution(vector<int> food_times, long long k) {
    k++;
    long long threshold = getThreshold(food_times, k);
    for (int& time : food_times) {
        long long amt = (time < threshold) ? time : threshold;
        time -= amt;
        k -= amt;
    }
    
    for (int i = 0; i < food_times.size(); i++) {
        if (food_times[i] > 0) k--;
        if (k == 0) return i+1;
    }
    
    return -1;
}