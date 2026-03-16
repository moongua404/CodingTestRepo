#include <iostream>
using namespace std;

void solution() {
	while(true) {
		int checksum = 0;
		int idx = 0;
		
		char ch;
		while(true) {
			idx++;

			ch = cin.get();
			if (ch == '\n' || ch == '#') break;
			if (ch == ' ') continue;
			checksum += (int(ch) - 64) * idx;
		}
		if (ch == '#') break;
		cout << checksum << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	
	solution();
	
	return 0;
}
