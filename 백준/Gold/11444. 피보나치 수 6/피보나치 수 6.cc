#include <iostream>
#include <map>

using namespace std;

// f(n)^2 + f(n+1)^2 = f(2n)
class Fibo {
    static map<long, long> cache;
public:
    static void initial() {
        cache.insert({0, 0});
        cache.insert({1, 1});
        cache.insert({2, 1});
        cache.insert({3, 2});
        cache.insert({4, 3});
    }
    static long fibo(long n) {
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }
        if (n % 2 != 0) {
            long nPer2 = fibo(n/2);
            long nPlus1Per2 = fibo((n+1)/2);
            long v = (nPer2 * nPer2 + nPlus1Per2 * nPlus1Per2) % 1000000007;
            cache.insert({n, v});
            return (v);
        }
        long nPlus1 = fibo(n+1);
        long nMinus1 = fibo(n-1);
        long v = (nPlus1 - nMinus1) % 1000000007;
        if (v < 0) { v += 1000000007; }
        cache.insert({n, v});
        return v;
    }
};

std::map<long, long> Fibo::cache;

void solution() {
    long n;
    cin >> n;
    Fibo::initial();
    cout << (Fibo::fibo(n) % 1000000007);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    solution();
    return 0;
}

/*
f(n) = 1 f(n-2) + 1 f(n-1)
f(n) = 1 f(n-3) + 2 f(n-2)
f(n) = 2 f(n-4) + 3 f(n-3)
f(n) = 3 f(n-5) + 5 f(n-4)
f(n) = 5 f(n-6) + 8 f(n-5)
f(n) = 8 f(n-7) + 13 f(n-6)


0  1  2  3  4  5  6   7   8   9  10  11   12   13   14   15   16    17
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

f(1, 2) = f(2)
f(2, 3) = f(5)
f(3, 4) = f(7)
f(4, 5) = f(9)
f(5, 6) = f(11)
f(6, 7) = f(13)
f(7, 8) = f(15)

// f(n)^2 + f(n+1)^2 = f(2n)
f(10) -> f(5, 6)
*/