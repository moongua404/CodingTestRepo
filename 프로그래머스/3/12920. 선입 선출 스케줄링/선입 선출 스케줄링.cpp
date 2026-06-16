/*
바이너리 서치
*/

#include <string>
#include <vector>

using namespace std;

int runnableJobs(vector<int>& cores, int time) {
    int acc = cores.size();
    for (int core : cores) {
        acc += time / core;
    }
    return acc;
}

int solution(int n, vector<int> cores) {
    int minV = 0, maxV = 50001; // maxV is able, minV is not
    while(minV + 1 < maxV) {
        int midV = (minV + maxV) / 2;
        if (runnableJobs(cores, midV) >= n) {
            maxV = midV;
        } else {
            minV = midV;
        }
    }
    
    n -= runnableJobs(cores, maxV-1);
    for (int i = 0; i < cores.size(); i++) {
        if (maxV % cores[i] == 0) n--;
        if (n <= 0) return i+1;
    }
}