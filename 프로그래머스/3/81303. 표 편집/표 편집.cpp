/*
빡구현?
redo log 캐시

delete하면 database[i]를 비활성화
    next[before[i]] = next[i], before[next[i]] = before[i];
recover하면
    next[before[i]] = i, before[next[i]] = i;
*/

#include <string>
#include <vector>

using namespace std;

pair<char, int> parseCommand(string s) {
    if (s[0] == 'C' || s[0] == 'Z') return {s[0], -1};
    return {s[0], stoi(s.substr(2, -1))};
}

string solution(int n, int k, vector<string> cmd) {
    vector<bool> database(n);  // 0 1 2 3 4 5 6 7 (index)
    vector<int> next(n);       // 1 2 3 4 5 6 7 X (value)
    vector<int> before(n);     // X 0 1 2 3 4 5 6 (value)
    vector<int> redoLog;
    
    // 데이터베이스 초기화
    next[n-1] = -1;
    before[0] = -1;
    for (int i = 0; i < n; i++) {
        database[i] = true;
        if (i != n-1) {
            next[i] = i+1;
        }
        if (i != 0) {
            before[i] = i-1;
        }
    }
    
    // 커맨드 수행
    int cursor = k;
    for (string command : cmd) {        
        pair<char, int> meta = parseCommand(command);
        if (meta.first == 'U') {
            for (int i = 0; i < meta.second; i++) {
                cursor = before[cursor];
            }
            continue;
        }
        if (meta.first == 'D') {
            for (int i = 0; i < meta.second; i++) {
                cursor = next[cursor];
            }
            continue;
        }
        if (meta.first == 'C') {
            database[cursor] = false; // 비활성화
            redoLog.push_back(cursor); // 캐싱
            // 다음 커서 위치
            int nextCursor = next[cursor];
            if (nextCursor == -1) nextCursor = before[cursor];
            // next와 before 갱신
            if (before[cursor] != -1) next[before[cursor]] = next[cursor];
            if (next[cursor] != -1) before[next[cursor]] = before[cursor];
            // 커서 이동
            cursor = nextCursor;
            continue;
        }
        if (meta.first == 'Z') {
            int t = redoLog.back();
            redoLog.pop_back();
            database[t] = true;
            
            if (before[t] != -1) next[before[t]] = t;
            if (next[t] != -1) before[next[t]] = t;
        }
    }
    
    // 결과 출력
    string answer = "";
    answer.reserve(n);
    for (int i = 0; i < n; i++) {
        answer += (database[i]) ? 'O' : 'X';
    }
    return answer;
}