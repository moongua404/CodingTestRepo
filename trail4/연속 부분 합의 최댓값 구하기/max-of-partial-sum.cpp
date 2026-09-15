#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int N;
    cin >> N;
    int globalOptimum = 0x80000000, localOptimum = 0;
    for (int i = 0; i < N; i++) {
        int v;
        cin >> v;
        localOptimum += v;
        if (localOptimum < v) localOptimum = v;
        if (globalOptimum < localOptimum) globalOptimum = localOptimum;
    }
    cout << globalOptimum;


    return 0;
}