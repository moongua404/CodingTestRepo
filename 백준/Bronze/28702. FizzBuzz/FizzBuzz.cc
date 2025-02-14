#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string input[3];
    for (int i = 0; i < 3; i++) {
        cin >> input[i];
    }

    int value, order;

    for (int i = 0; i < 3; i++) {
        if (input[i] != "Fizz" && input[i] != "Buzz" && input[i] != "FizzBuzz") {
            value = stoi(input[i]);
            order = i;
            break;
        }
    }

    int result = value + (3 - order);
    
    if (result % 3 == 0 && result % 5 == 0) {
        cout << "FizzBuzz";
    } else if (result % 3 == 0) {
        cout << "Fizz";
    } else if (result % 5 == 0) {
        cout << "Buzz";
    } else {
        cout << result;
    }

    return 0;
}


//숫자가 있으면 4번째를 계산하면 됨
//숫자가 없으면 - 없을 수가 없음. why? 3의 배수와 5의 배수이기에
