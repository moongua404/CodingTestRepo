#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

class WordMap {
public:
    int wordMap[26];
    int length;

    void convertMap(string s) {
        this->length = s.length();
        for (int i = 0; i < 26; i++) {
            wordMap[i] = 0;
        }
        for (int i = 0; i < s.length(); i++) {
            wordMap[int(s[i]-65)]++;
        }
    }
    bool isSimilar(WordMap other) {
        int sum = 0;
        for (int i = 0; i < 26; i++) {
            int v = abs(this->wordMap[i] - other.wordMap[i]);
            if (v >= 2) {
                return false;
            }
            if (v == 1) {
                sum += 1;
            }
        }
        if (this->length == other.length) {
            return sum == 0 || sum == 2;
        }
        return sum <= 1;
    }
};

class Path {
public:
    long distance;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string stdSentence;
    string* sentences = new string[N];
    cin >> stdSentence;
    for (int i = 0; i < N-1; i++) {
        cin >> sentences[i];
    }
    
    WordMap stdMap;
    WordMap* maps = new WordMap[N-1];
    stdMap.convertMap(stdSentence);
    for (int i = 0; i < N-1; i++) {
        maps[i].convertMap(sentences[i]);
    }
    int count = 0;
    for (int i = 0; i < N-1; i++) {
        if (stdMap.isSimilar(maps[i])) {
            count++;
        }
    }
    cout << count;

    return 0;
}