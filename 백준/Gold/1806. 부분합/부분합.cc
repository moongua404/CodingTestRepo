#include <iostream>
using namespace std;

void solution() {
	int N, S;
	cin >> N >> S;
	int* arr = new int[N];

	int sum = 0;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum < S) {
		cout << 0;
		return;
	}

	int minLength = N;
	sum = 0;
	int i = 0, j = 0;

	while(i < N) {
		if (sum >= S) {
			sum -= arr[i];
			i++;
		} else {
			if (j == N) {
				break;
			}
			sum += arr[j];
			j++;
		}
		if (sum >= S && j-i < minLength) {
			minLength = j-i;
		}
	}
	
	cout << minLength;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}