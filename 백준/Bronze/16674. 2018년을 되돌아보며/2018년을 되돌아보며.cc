#include <iostream>
using namespace std;

void solution() {
	int two = 0, zero = 0, one = 0, eight = 0;
	string s;
	cin >> s;

	for (char ch : s) {
		if (ch == '2') two++;
		else if (ch == '0') zero++;
		else if (ch == '1') one++;
		else if (ch == '8') eight++;
		else {
			cout << 0;
			return;
		}
	}
	if (two == 0 || zero == 0 || one == 0 || eight == 0) cout << 1;
	else if (two == zero && zero == one && one == eight) cout << 8;
	else cout << 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}