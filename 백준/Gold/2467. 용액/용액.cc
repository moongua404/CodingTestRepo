/**
 * 시작이랑 끝에서부터 다가와 아오에
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int MAX_INT = 0x7FFFFFFF;

int abs(int v) {
	return v > 0 ? v : -v;
}

void solution() {
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0, right = N-1;
	int minV = MAX_INT, targetLeft, targetRight;

	while (left < right) {
		int sum = arr[left] + arr[right];
		if (abs(sum) <= minV) {
			minV = abs(sum);
			targetLeft = left;
			targetRight = right;
		}
		if (sum == 0) {
			break;
		}
		if (sum > 0) {
			right--;
		} else {
			left++;
		}
	}

	cout << arr[targetLeft] << ' ' << arr[targetRight];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}