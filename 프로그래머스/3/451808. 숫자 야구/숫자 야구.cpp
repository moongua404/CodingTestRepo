#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

extern string submit(int);

vector<int> split(int v) {
    vector<int> vec;
    for (int d = 1000; d >= 1; d/=10) {
        vec.push_back(v / d);
        v %= d;
    }
    return vec;
}

// freq size should 10
int pick(vector<int>& vec, vector<int>& freq) {
    int bestV = 9999;
    int bestS = 0x7FFFFFFF;
    for (int v : vec) {
        vector<int> res = split(v);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        int score = 10000;
        for (int r : res) {
            score /= 10;
            score *= (freq[r]+1);
        }
        if (score < bestS) {
            bestS = score;
            bestV = v;
        }
    }
    return bestV;
}

pair<int, int> parseToResult(string res) {
    return {res[0] - '0', res[3] - '0'};
}

vector<int> filter(vector<int>& vec, int base, int strike, int ball) {
    vector<int> newVec;
    
    vector<int> parsedBase = split(base);
    for(int& v : vec) {
        if (v == base) continue;
        vector<int> parsed = split(v);
        int vStrike = 0, vBall = 0;
        for (int i = 0; i < 4; i++) {
            if (parsed[i] == parsedBase[i]) vStrike++;
            else {
                for (int j = 0; j < 4; j++) {
                    if (parsed[j] == parsedBase[i]) {
                        vBall++;
                        break;
                    }
                }
            }
        }
        if (vStrike == strike && vBall == ball) {
            newVec.push_back(v);
        }
    }
    return newVec;
}

int solution(int n) {
    vector<int> vec;
    vec.reserve(9000);
    for (int i = 1000; i <= 9999; i++) {
        vec.push_back(i);
    }
    
    vector<int> freq(10, 0);
    freq[0] = 1;
    for (int _ = 0; _ <= 30; _++) {
        if (vec.size() == 1) return vec[0];
        int v = pick(vec, freq);
        string response = submit(v);
        if (response == "4S 0B") return v;
        pair<int, int> result = parseToResult(response);
        vec = filter(vec, v, result.first, result.second);
    }
    
    return 0;
}

// 6304