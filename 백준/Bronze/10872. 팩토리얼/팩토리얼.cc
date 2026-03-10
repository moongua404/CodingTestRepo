#include <iostream>
using namespace std;

void solution() {
	int n;
	cin >> n;

	int res = 1;
	for (int i = 2; i < n+1; i++) {
		res *= i;
	}

	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}