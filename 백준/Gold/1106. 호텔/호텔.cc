/**
 * DP
 *  - 1 gain을 달성하기 위한 최적은?
 *  - 2 gain을 달성하기 위한 최적은?
 *  - ...
 *  - N gain을 달성하기 위한 최적은?
 *  - N + a gain을 달성하기 위한 최적은? // a는 가장 많은 gain - 1
 */

#include <iostream>
using namespace std;

int MAX_INT = 0x7FFFFFFF;

struct Node {
	int cost, gain;
public:
	Node() {}
	Node(int cost, int gain) : cost(cost), gain(gain) { }
};

void solution() {
	int count = 0;

	int C, N, maxGain = 0;
	cin >> C >> N;

	Node* cities = new Node[N];
	for (int i = 0; i < N; i++) {
		int c, g;
		cin >> c >> g;
		if (g > maxGain) maxGain = g;
		cities[i] = Node(c, g);
	}
	maxGain++;
	
	int* minCost = new int[C + maxGain + 1];
	for (int i = 0; i < C + maxGain + 1; i++) {
		minCost[i] = 0x7FFFFFFF;
	}
	minCost[0] = 0;

	for (int targetGain = 1; targetGain < C + maxGain; targetGain++) {
		for (int cityIndex = 0; cityIndex < N; cityIndex++) {
			int beforeGain = targetGain - cities[cityIndex].gain;
			if (beforeGain >= 0 && minCost[beforeGain] != 0x7FFFFFFF) {
				int newCost = minCost[beforeGain] + cities[cityIndex].cost;
				if (minCost[targetGain] > newCost) minCost[targetGain] = newCost;
			}
		}
	}

	int result = 0x7FFFFFFF;
	for (int i = C; i < C + maxGain + 1; i++) {
		if (minCost[i] < result) {
			result = minCost[i];
		}
	}

	cout << result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}