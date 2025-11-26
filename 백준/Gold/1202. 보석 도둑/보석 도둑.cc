#include <iostream>
#include <queue>
#include <set>

using namespace std;

class Gem {
public:
    int m, v;
    Gem() : m(0), v(0) { }
    bool operator< (const Gem gem) const {
        return this->v < gem.v;
    }
};

class Knapsack {
public:
    int c;
    Knapsack(int c = 0) : c(c) { }
    bool operator< (const Knapsack knapsack) const {
        return this->c < knapsack.c;
    }
};

void solution() {
    int N, K;
    cin >> N >> K;
    Gem* tempGems = new Gem[N];
    multiset<Knapsack> knapsacks;

    for (int i = 0; i < N; i++) {
        Gem gem;
        cin >> tempGems[i].m >> tempGems[i].v;
    }
    for (int i = 0;i < K; i++) {
        int c;
        cin >> c;
        knapsacks.insert(Knapsack(c));
    }

    priority_queue<Gem> gems(tempGems, tempGems + N);

    int affected = 0;
    long sum = 0;
    while (!gems.empty() && affected != K) {
        Gem locallyBiggest = gems.top();
        gems.pop();
        auto it = knapsacks.lower_bound(Knapsack(locallyBiggest.m));
        if (it != knapsacks.end()) {
            sum += locallyBiggest.v;
            affected++;
            knapsacks.erase(it);
        }
    }
    cout << sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();

    return 0;
}
