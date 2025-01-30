#include <iostream>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCaseCount;
    cin >> testCaseCount;
    for (int testCase = 0; testCase < testCaseCount; testCase++) {
        int N;
        cin >> N;

        map<string, int> clothes;

        for (int i = 0; i < N; i++) {
            string s1, s2;
            cin >> s1 >> s2;
            if (clothes.find(s2) != clothes.end()) {
                clothes[s2] = clothes[s2]+1;
            } else {
                clothes[s2] = 1;
            }
        }

        int value = 1;

        for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
            value *= (iter->second+1);
        }

        cout << value-1 << '\n';
    }

    return 0;
}