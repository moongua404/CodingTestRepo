#include <iostream>
#include <algorithm>
#include <string>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    class Calc {
    public:
        deque<int> arr;
        bool frontDirection;

        Calc() {
            frontDirection = true;
        }

        void pop() {
            if (frontDirection) {
                arr.pop_front();
            } else {
                arr.pop_back();
            }
        }
        int get() {
            int v;
            if (frontDirection) {
                v = arr.front();
                arr.pop_front();
            } else {
                v = arr.back();
                arr.pop_back();
            }
            return v;
        }
    };

    int T;
    cin >> T;
    for (int trial = 0; trial < T; trial++) {
        string instruction, line;
        int length;
        cin >> instruction >> length >> line;
        line[line.length()-1] = ',';
        Calc calc;
        int start = 1;
        
        for (int i = 0; i < length; i++) {
            int iter = line.find(",", start);
            string s = line.substr(start, iter-start);
            start = iter+1;
            calc.arr.push_back(stoi(s));
        }

        bool isError = false;

        for (int i = 0; i < instruction.length(); i++) {
            if (instruction[i] == 'R') {
                calc.frontDirection = !calc.frontDirection;
            } else {
                if (calc.arr.empty()) {
                    isError = true;
                    break;
                }
                calc.pop();
            }
        }

        if (isError) {
            cout << "error\n";
        } else {
            cout << "[";
            if (!calc.arr.empty()) {
                cout << calc.get();
            }
            while (!calc.arr.empty()) {
                cout << "," << calc.get();
            }
            cout << "]\n";
        }
    }
}