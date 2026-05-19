/*
banned_id별로 가능한 id를 매핑
그냥 가능성 다 따져보자 <= 8! <= 50,000
-> 전략 : 백트래킹
*/

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

bool match(string s, string p) {
    if (s.length() != p.length()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (p[i] == '*') continue;
        if (s[i] != p[i]) return false;
    }
    return true;
}

class Recur {
    map<int, vector<string>> availableIdxByPatternIdx;
    int targetSize;
public:
    Recur(vector<string> user_id, vector<string> banned_id) {
        targetSize = banned_id.size();
        for (int i = 0; i < targetSize; i++) {
            vector<string> availableIds;
            for (string id : user_id) {
                if (match(id, banned_id[i])) availableIds.push_back(id);
            }
            availableIdxByPatternIdx.insert({i, availableIds});
        }
    }
    
    set<set<string>> recur(int idx, set<string> containedIds) {
        if (idx == targetSize) {
            return set<set<string>>{containedIds};
        }
        set<set<string>> res;
        for (string id : availableIdxByPatternIdx[idx]) {
            if (containedIds.find(id) == containedIds.end()) {
                containedIds.insert(id);
                set<set<string>> rec = recur(idx+1, containedIds);
                for (set<string> s : rec) {
                    res.insert(s);
                }
                containedIds.erase(id);
            }
        }
        return res;
    }
};

int solution(vector<string> user_id, vector<string> banned_id) {
    Recur recur(user_id, banned_id);
    return recur.recur(0, set<string>{}).size();
}