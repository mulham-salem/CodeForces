#include <iostream>
using namespace std;

using int64 = long long;

int64 modPow(int64 base, int64 exp, int64 mod) {
    int64 result = 1 % mod;
    base %= mod;

    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;

        base = (base * base) % mod;
        exp >>= 1;
    }

    return result;
}

int main() {
    int64 n, m;
    cin >> n >> m;

    cout << (modPow(3, n, m) - 1 + m) % m << '\n';

    return 0;
}
