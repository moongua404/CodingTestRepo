/*
greedy
위상정렬?

트리 => 부모 노드는 하나
리프에서부터 자신을 0을 만들며 위로 올라옴
*/

#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges) {
    int size = a.size();
    vector<unordered_set<int>> m(size); // [노드]{갈 수 있는 노드}
    for (vector<int> edge: edges) {
        m[edge[0]].insert(edge[1]);
        m[edge[1]].insert(edge[0]);
    }
    
    int root = -500; // 반드시 갱신됨
    for (int i = 0; i < size; i++) {
        if (m[i].size() == 1) {
            root = i;
            break;
        }
    }
    
    vector<vector<pair<int, int>>> tree; // [층]{노드, 부모}
    
    int level = 0;
    queue<pair<int, int>> q; // [노드][레벨]
    q.push({root, 0});
    unordered_set<int> s{};
    s.insert(root);
    
    while(!q.empty()) {
        pair<int, int> pick = q.front();
        q.pop();
        
        
        for (int v : m[pick.first]) { // pick.first -> v
            if (s.find(v) != s.end()) continue;
            s.insert(v);
            
            while (pick.second+1 > tree.size()) {
                level = pick.second;
                tree.push_back({});
            }
            tree[pick.second].push_back({v, pick.first});
            
            q.push({v, pick.second+1});
        }
    }
    
    vector<long long> temp(size);
    for (int i = 0; i < size; i++) {
        temp[i] = a[i];
    }
    
    long long cnt = 0;
    
    for (int i = level; i >= 0; i--) {
        for (pair<int, int> node : tree[i]) {
            temp[node.second] += temp[node.first];
            if (temp[node.first] > 0) cnt += temp[node.first];
            else cnt -= temp[node.first];
        }
    }
    
    if (temp[root] != 0) return -1;
    return cnt;
}