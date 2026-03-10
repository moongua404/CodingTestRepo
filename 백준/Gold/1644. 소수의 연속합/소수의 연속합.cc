/**
 * 소수를 구해
 * 투포인터를 갖다가 훑어
 * 갯수를 찍어
 */

#include <iostream>
#include <vector>
using namespace std;

vector<int> getSosu(int N) {
	int* filter = new int[N+1];
	for (int i = 0; i < N+1; i++) {
		filter[i] = true;
	}
	vector<int> result;
	for (int i = 2; i < N+1; i++) {
		if (filter[i]) {
			result.push_back(i);
			for (int j = i; j < N+1; j += i) {
				filter[j] = false;
			}
		}
	}
	return result;
}

void solution() {
	int N;
	cin >> N;

	vector<int> sosu = getSosu(N);

	int first = 0, last = 0, sum = 0, count = 0;
	while(true) {
		if (sum < N) {
			if (last >= sosu.size()) break;
			sum += sosu[last];
			last++;
		} else {
			sum -= sosu[first];
			first++;
		}
		if (sum == N) { count++; }
	}

	cout << count;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}