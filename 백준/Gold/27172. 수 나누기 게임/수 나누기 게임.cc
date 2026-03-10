/**
 * 그냥 다 나눠보면 안되나...?
 * 맵에다 넣어두고 배수를 검색?
 * 
 * map<int:값, int:점수>
 */

#include <iostream>
#include <map>
using namespace std;

int RANGE_MAX = 1000000;

void solution() {
	map<int, int> m;

	int N;
	cin >> N;
	int* index = new int[N];
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		m.insert({x, 0});
		index[i] = x;
	}

	for (int i = 0; i < N; i++) {
		int t = index[i];
		int score = 0;
		for (int v = t*2; v <= RANGE_MAX; v += t) {
			if (m.find(v) != m.end()) {
				score++;
				m[v]--;
			}
		}
		m[t] += score;
	}

	for (int i = 0; i < N; i++) {
		cout << m[index[i]] << ' ';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}