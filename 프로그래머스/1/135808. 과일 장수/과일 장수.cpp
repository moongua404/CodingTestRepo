#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    vector<int> v;
    for (int i = 0; i < k; i++) { v.push_back(0); }
    
    for (int i = 0; i < score.size(); i++) {
        v[score[i]-1]++;
    }
    
    int acc = 0;
    int result = 0;
    for (int i = k-1; i >= 0; i--) {
        acc += v[i];
        if (acc >= m) {
            result += m * (i+1) * (acc / m);
            acc %= m;
        }
    }
    return result;
}