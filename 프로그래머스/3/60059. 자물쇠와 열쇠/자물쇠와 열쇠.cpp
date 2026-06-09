/*
홈을 한 점에 대해 상대 좌표화할 수 있나?
why not 이긴 함

Lock을 한 점에 대해 상대 좌표화 한 후, 
key의 모든 돌기 좌표에 대해 상대 좌표한 좌표들을 순회하며
key의 상대좌표가 lock의 모든 상대 좌표를 포함하는지 확인

회전은..?
    특점 점에 대해 일치하거나 회전했을 때 일치한다면
        상대 좌표를 (1, 1), (1, -1), (-1, 1), (-1, -1)을 곱했을 때 일치함

Remapping : O(n^2)
탐색 : O(n^2 log n) // O(n^2)까지는 내릴 수 있어 보이긴함 <- 굳이
-> O(n^2 log n)
*/

#include <string>
#include <vector>
#include <set>

using namespace std;

class Remap {
    set<pair<int, int>> poses;
    pair<int, int> pivot;
    Remap(pair<int, int> p) : pivot(p) { }
public:
    static Remap build(vector<pair<int, int>>& original, pair<int, int> pivot) {
        Remap remap(pivot);
        for (pair<int, int> each : original) {
            if (each == pivot) continue;
            remap.poses.insert(
                {each.first-pivot.first, each.second-pivot.second});
        }
        return remap;
    }
    
    // 겹치지 않았을 때 포함하려면 범위를 벗어나야 함
    bool contains(Remap& t, pair<int, int> adapter, int size) {
        int lockCount = 0;
        for (pair<int, int> base : this->poses) {
            // (1, 2) -> (-2, 1), (-1, -2), (2, -1)
            int f = base.first*adapter.first, s = base.second*adapter.second;
            if (adapter.first * adapter.second < 0) {
                int temp = f;
                f = s;
                s = temp;
            }
            if (t.poses.find({f, s}) == t.poses.end()) {
                // 상대 좌표 -> 절대 좌표
                int ff = f + t.pivot.first;
                int ss = s + t.pivot.second;
                if (ff >= 0 && ff < size && ss >= 0 && ss < size) {
                    return false;
                }
                continue;
            }
            lockCount++;
        }
        return lockCount == t.poses.size();
    }
};

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int keySize = key.size();
    int lockSize = lock.size();
    vector<pair<int, int>> keyPos;
    vector<pair<int, int>> lockPos;
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) { // N by N
            if (key[i][j] == 1) keyPos.push_back({i, j});
        }
    }
    for (int i = 0; i < lockSize; i++) {
        for (int j = 0; j < lockSize; j++) {
            if (lock[i][j] == 0) lockPos.push_back({i, j});
        }
    }
    
    if (lockPos.empty()) return true; // early return
    
    Remap lockPivot = Remap::build(lockPos, lockPos[0]); // segfault safe
    
    for (pair<int, int> pivot : keyPos) {
        Remap remap = Remap::build(keyPos, pivot);
        for (int i = -1; i <= 1; i += 2) {
            for (int j = -1; j <= 1; j += 2) {
                if (remap.contains(lockPivot, {i, j}, lockSize)) {
                    return true;
                }
            }
        }
    }
    
    return false;
}