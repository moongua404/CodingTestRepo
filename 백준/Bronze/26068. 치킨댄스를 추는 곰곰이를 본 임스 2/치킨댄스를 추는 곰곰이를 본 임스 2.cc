#include <iostream>
#include <math.h>
#include <regex>
using namespace std;

void solution() {
	int c = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		regex pattern("D-([0-9]+)");
		smatch matches;
		regex_search(s, matches, pattern);
		if (stoi(matches[1]) <= 90) {
			c++;
		}
	}
	cout << c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}