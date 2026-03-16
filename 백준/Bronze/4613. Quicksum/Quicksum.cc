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
			if (ch == '#') return;
			if (ch == '\n') break;
			if (ch == ' ') continue;
			checksum += (int(ch) - 64) * idx;
		}
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
