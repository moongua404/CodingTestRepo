#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if (n > s) {
        return vector<int>({-1});
    }
    int v = s / n;
    int left = s - n * v;
    
    vector<int> answer;
    for (int i = 0; i < n; i++) {
        if (n - left <= i) {
            answer.push_back(v+1);
        } else {
            answer.push_back(v);
        }
    }
    
    return answer;
}

int main() {
    solution(4, 10);

    return 0;
}