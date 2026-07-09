#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

long long modPow(long long base, long long exp) {
    long long res = 1;
    base %= MOD;

    while (exp > 0) {
        if (exp & 1)
            res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long p4 = modPow(4, n);
    long long p2 = modPow(2, n);
    long long inv2 = modPow(2, MOD - 2);

    long long ans = (p4 + p2) % MOD;
    ans = ans * inv2 % MOD;

    cout << ans;

    return 0;
}
