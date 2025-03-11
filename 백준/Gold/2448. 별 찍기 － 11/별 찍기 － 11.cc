#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> drawTriangle(int size) {
    if (size == 3) {
        vector<string> temp;
        temp.push_back("  *  ");
        temp.push_back(" * * ");
        temp.push_back("*****");
        return temp;
    }
    vector<string> vec(size);
    vector<string> temp = drawTriangle((size)/2);

    for (int i = 0; i < size/2; i++) {
        for (int j = 0; j < size/2; j++) {
            vec[j] += " ";
        }
    }
    for (int j = 0; j < size/2; j++) {
        vec[j] += temp[j];
    }
    for (int i = 0; i < size/2; i++) {
        for (int j = 0; j < size/2; j++) {
            vec[j] += " ";
        }
    }

    for (int i = 0; i < size/2; i++) {
        vec[i+size/2] += temp[i] + " " + temp[i];
    }

    return vec;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<string> vec = drawTriangle(N);

    for (int i = 0; i < N; i++) {
        cout << vec[i] << "\n";
    }

    return 0;
}
