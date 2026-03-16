#include <iostream>
using namespace std;

void solution() {
	int sum = 0;
	for (int i = 0; i < 6; i++) {
		int v;
		cin >> v;
		sum += v;
	}
	cout << sum * 5;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}