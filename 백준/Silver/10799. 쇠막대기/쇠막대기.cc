#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string line;
    cin >> line;

    bool canLaser = false;
    int total = 0;
    int stack = 0;

    for (char ch : line) {
        if (ch == '(') {
            canLaser = true;
            stack++;
        } else {
            if (canLaser) {
                stack--;
                total += stack;
            } else {
                total++;
                stack--;
            }
            canLaser = false;
        }
    }
    cout << total;
    
    return 0;
}

/*
레이저를 발견하면 stack의 size만큼 total에 더해 (잘린 조각)
나무가 끝날 때 1씩 더해 (원래 판)

뭐야, stack도 필요없는데?
*/