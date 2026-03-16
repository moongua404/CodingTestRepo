#include <iostream>
using namespace std;

void solution() {
	int N, B, H, W;
	cin >> N >> B >> H >> W;

	int mincost = 0x7FFFFFFF;
	
	for (int i = 0; i < H; i++) {
		int p;
		cin >> p;
		for (int j = 0; j < W; j++) {
			int a;
			cin >> a;
			if (N > a) continue;
			if (N * p > B) continue;
			if (mincost > N * p) mincost = N * p;
		}
	}

	if (mincost == 0x7FFFFFFF) {
		cout << "stay home";
		return;
	}
	cout << mincost;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
	
	solution();
	
	return 0;
}
