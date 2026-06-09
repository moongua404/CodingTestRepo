#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    // brute force
    int size = prices.size();
    vector<int> answer;
    answer.reserve(size);
    
    for (int i = 0; i < size; i++) {
        int v = 0;
        for (int j = i+1; j < size; j++) {
            v++;
            if (prices[i] > prices[j]) break;
        }
        answer.push_back(v);
    }
    
    return answer;
}