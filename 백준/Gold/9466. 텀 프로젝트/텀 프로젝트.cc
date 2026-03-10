/**
 * 범위 : 100k
 * 
 * loop를 찾는게 관건
 * loop를 찾은걸 다 제외시키고
 * 남은 node의 갯수를 세면 됨
 */

#include <iostream>
#include <set>
using namespace std;

struct Node {
	int next;
	bool visited;
	bool hasTeam;

public:
	Node() { }
	Node(int next) : next(next), visited(false), hasTeam(false) { }
};

void testcase() {
	int n;
	cin >> n;
	Node* arr = new Node[n];
	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		arr[i] = Node(v-1);
	}

	for (int i = 0; i < n; i++) {
		if (arr[i].visited) continue;

		set<int> visited;
		arr[i].visited = true;
		int currentIdx = i;
		while(true) {
			visited.insert(currentIdx);
			int nextIdx = arr[currentIdx].next;

			if (visited.find(nextIdx) != visited.end()) {
				// 팀 만들어진거 쫘라락 유남생
				int target = nextIdx;
				while (true) {
					arr[nextIdx].hasTeam = true;
					if (arr[nextIdx].next == target) {
						break;
					}
					nextIdx = arr[nextIdx].next;
				}

				break;
			}

			if (arr[nextIdx].visited) break;
			arr[nextIdx].visited = true;
			currentIdx = nextIdx;
		}
	}

	int count = 0;
	for (int i = 0; i < n; i++) {
		if (!arr[i].hasTeam) count++;
	}

	cout << count;
}

void solution() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		testcase();
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

	solution();
	
	return 0;
}