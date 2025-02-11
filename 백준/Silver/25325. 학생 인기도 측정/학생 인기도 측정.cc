#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Node {
public:
    string name;
    int popularity;
    Node (string name = "", int popularity = 0) : name(name), popularity(popularity) {}
    static bool cpr(Node one, Node other) {
        if (one.popularity == other.popularity) {
            return one.name < other.name;
        }
        return one.popularity > other.popularity;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    unordered_map<string, Node> data;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        data[s] = Node(s);
    }
    cin.ignore();

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        int idx = 0;
        int next;
        while((next = line.find(' ', idx)) != -1) {
            data[line.substr(idx, next - idx)].popularity += 1;
            idx = next + 1;
        }
        data[line.substr(idx)].popularity += 1;
    }

    Node* result = new Node[N];

    int idx = 0;
    for (auto v : data) {
        result[idx] = v.second;
        idx++;
    }

    sort(result, result+N, Node::cpr);

    for (int i = 0; i < N; i++) {
        cout << result[i].name << ' ' << result[i].popularity << '\n';
    }

    return 0;
}