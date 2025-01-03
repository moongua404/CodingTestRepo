#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
using namespace std;

class Submit {
    int* scores;
    int trials;
    int lastSubmit;
    int problemCount;
public:
    Submit() {}
    Submit(int n) {
        scores = new int[n];//뉴가 안된다
        for (int i = 0; i < n; i++) {
            scores[i] = 0;
        }
        problemCount = n;
        trials = 0;
        lastSubmit = 0;
    }
    void update(int submitIndex, int problemIdx, int score) {
        trials++;
        lastSubmit = submitIndex;
        if (scores[problemIdx] < score) {
            scores[problemIdx] = score;
        }
    }
    static bool compare(const Submit first, const Submit second) {
        int firstSum = 0, secondSum = 0;
        for (int i = 0; i < first.problemCount; i++) {
            firstSum += first.scores[i];
        }
        for (int i = 0; i < second.problemCount; i++) {
            secondSum += second.scores[i];
        }
        if (firstSum == secondSum) {
            if (first.trials == second.trials) {
                return first.lastSubmit < second.lastSubmit;
            }
            return first.trials < second.trials;
        }
        return firstSum > secondSum;
    }
};

void KCPC() {
    int teamCount, problemCount, myTeamId, logCount;
    cin >> teamCount >> problemCount >> myTeamId >> logCount;

    Submit* scores = new Submit[teamCount];
    for (int i = 0; i < teamCount; i++) {
        scores[i] = Submit(problemCount);
    }

    for (int logIdx = 0; logIdx < logCount; logIdx++) {
        int teamIdx, problemIdx, score;
        cin >> teamIdx >> problemIdx >> score;
        scores[teamIdx-1].update(logIdx, problemIdx-1, score);
    }

    int rank = 1;
    for (int i = 0; i < teamCount; i++) {
        if (Submit::compare(scores[i], scores[myTeamId-1])) {
            rank++;
        }
    }
    cout << rank << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    for (int testCase = 0; testCase < T; testCase++) {
        KCPC();
    }

    return 0;
}