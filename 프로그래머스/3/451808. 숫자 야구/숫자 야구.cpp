#include <string>
#include <vector>

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

pair<int, int> validate(int answer, int submitted) {
    vector<int> parsed = split(answer);
    vector<int> parsedBase = split(submitted);
    int vStrike = 0, vBall = 0;
    for (int i = 0; i < 4; i++) {
        if (parsed[i] == parsedBase[i]) {
            vStrike++;
            continue;
        }
        for (int j = 0; j < 4; j++) {
            if (parsed[j] == parsedBase[i]) {
                vBall++;
                break;
            }
        }
    }
    return {vStrike, vBall};
}

int pick(vector<int>& vec) {
    int bestV; // 최적의 값
    int bestC = 0x7FFFFFFF; // 그 때 최악의 경우의 수
    
    for (int v : vec) {
        int worst = 0;
        for (int strike = 0; strike <= 4; strike++) {
            for (int ball = 0; ball <= 4; ball++) {
                if (strike + ball > 4) continue;
                int cases = 0;
                for (int o : vec) {
                    pair<int, int> res = validate(o, v);
                    if (res.first == strike && res.second == ball) cases++;
                }
                if (cases > worst) worst = cases;
            }
        }
        if (worst < bestC) {
            bestC = worst;
            bestV = v;
        }
    }
    
    return bestV;
}

vector<int> filter(vector<int>& vec, int base, int strike, int ball) {
    vector<int> newVec;
    
    for(int& v : vec) {
        if (v == base) continue;
        pair<int, int> res = validate(v, base);
        if (res.first == strike && res.second == ball) {
            newVec.push_back(v);
        }
    }
    return newVec;
}

int solution(int n) {
    vector<int> vec;
    vec.reserve(9000);
    for (int i = 1000; i <= 9999; i++) {
        vector<int> t = split(i);
        if (t[0] == t[1] || t[0] == t[2] || t[0] == t[3]
            || t[1] == t[2] || t[1] == t[3] || t[2] == t[3]) continue;
        vec.push_back(i);
    }
    
    for (int _ = 0; _ <= 30; _++) {
        if (vec.size() == 1) return vec[0];
        int v = 1234;
        if (_ != 0) v = pick(vec);
        string response = submit(v);
        if (response == "4S 0B") return v;
        pair<int, int> result = {response[0] - '0', response[3] - '0'};
        vec = filter(vec, v, result.first, result.second);
    }
    return 0;
}