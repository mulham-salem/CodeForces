#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long mn = LLONG_MAX;
    long long mx = LLONG_MIN;

    for (long long p = 1; p * p * p <= n; p++) {
        if (n % p) continue;

        long long rem = n / p;

        for (long long q = p; q * q <= rem; q++) {
            if (rem % q) continue;

            long long r = rem / q;

            long long vals[3] = {
                (p + 1) * (q + 2) * (r + 2) - n,
                (q + 1) * (p + 2) * (r + 2) - n,
                (r + 1) * (p + 2) * (q + 2) - n
            };

            for (long long x : vals) {
                mn = min(mn, x);
                mx = max(mx, x);
            }
        }
    }

    cout << mn << ' ' << mx << '\n';
    return 0;
}
