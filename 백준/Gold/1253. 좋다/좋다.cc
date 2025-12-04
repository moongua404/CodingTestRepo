#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void solution() {
    multiset<int> s;
    int cnt = 0;

    int N;
    cin >> N;
    int arr[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    sort(arr, arr+N);

    for (int i = 0; i < N; i++) {
        s.erase(s.find(arr[i]));
        for (int j = 0; j < N; j++) {
            if (i == j) { continue; }
            s.erase(s.find(arr[j]));
            bool found = s.find(arr[i] - arr[j]) != s.end();
            s.insert(arr[j]);
            if (found) {
                cnt++;
                break;
            }
        }
        s.insert(arr[i]);
    }

    cout << cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();
    return 0;
}