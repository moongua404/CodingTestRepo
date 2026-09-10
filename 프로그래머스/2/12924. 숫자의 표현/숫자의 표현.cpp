#include <string>
#include <vector>

using namespace std;

int sumUntil(int n) {
    return ((1 + n) * n) / 2;
}

bool exists(int n, int order) {
    n -= sumUntil(order-1);
    if (n > 0 && n % order == 0) return true;
    return false;
}

int solution(int n) {
    int acc = 0;
    for (int i = 1; i <= n; i++) {
        acc += (exists(n, i));
    }
    return acc;
}
