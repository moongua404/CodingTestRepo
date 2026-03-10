#include <iostream>
#include <math.h>
using namespace std;

void solution() {
	int s = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		s += v;
	}
	cout << s;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}