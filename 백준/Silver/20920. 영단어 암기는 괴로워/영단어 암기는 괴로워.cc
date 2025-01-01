#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
using namespace std;

class Word{
    string word;
    int freq;
public:
    Word(string word = "", int freq = 0) {
        this->word = word;
        this->freq = freq;
    }
    static bool compare(Word first, Word second) {
        if (first.freq == second.freq) {
            if (first.word.length() == second.word.length()) {
                return first.word < second.word;
            }
            return first.word.length() > second.word.length();
        }
        return first.freq > second.freq;
    }
    void addFreq() {
        freq++;
    }

    void print() {
        cout << this->word << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<string, Word> vocList;
    Word* output = new Word[N];

    for (int trial = 0; trial < N; trial++) {
        string sentence;
        cin >> sentence;
        if (sentence.length() >= M) {
            if (vocList.find(sentence) != vocList.end()) {
                vocList.find(sentence)->second.addFreq();
            } else {
                vocList.insert(make_pair(sentence, Word(sentence, 1)));
            }
        }
    }

    int idx = 0;
    for (auto iter : vocList) {
        output[idx] = iter.second;
        idx++;
    }

    sort(output, output+idx, Word::compare);

    for (int i = 0; i < idx; i++) {
        output[i].print();
    }

    return 0;
}
