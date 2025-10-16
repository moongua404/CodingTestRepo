#include <string>
#include <set>
#include <vector>

using namespace std;

vector<vector<int>> hanoi(int n, int start, int dest) {
    if (n == 1) {
        return {{start, dest}};
    }
    set<int> nums = {1, 2, 3};
    nums.erase(start);
    nums.erase(dest);
    int pass = *nums.begin();
    
    vector<vector<int>> history = hanoi(n-1, start, pass);
    history.push_back({start, dest});
    vector<vector<int>> temp = hanoi(n-1, pass, dest);
    for (vector<int> item : temp) {
        history.push_back(item);
    }
    return history;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    answer = hanoi(n, 1, 3);
    return answer;
}