#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int getOrder(vector<string> words) {
    int order = 0;
    
    string before = "";
    set<string> history;
    
    while(!words.empty()) {
        order++;
        string word = words.front();
        words.erase(words.begin());
        if ((history.find(word) != history.end())
                || word.length() <= 1
                || (before != "" && word[0] != before[before.length()-1])) {
            return order;
        }
        history.insert(word);
        before = word;
    }
    
    return -1;
}

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int order = getOrder(words);
    cout << order;
    if (order == -1) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back((order - 1) % n + 1);
        answer.push_back((order-1) / n + 1);
    }

    return answer;
}