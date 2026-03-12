#include <iostream>
using namespace std;

void solution() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int s1 = (1+n) * n / 2;
		cout << s1 << " " << n*n << " " << s1*2 << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}