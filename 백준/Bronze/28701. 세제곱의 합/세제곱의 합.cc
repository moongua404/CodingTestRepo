#include <iostream>
using namespace std;

void solution() {
	int N;
	cin >> N;
	int a = 0, b = 0;
	for (int i = 1; i < N+1; i++) {
		a += i;
		b += i*i*i;
	}

	cout << a << "\n" << a*a << "\n" << b << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}