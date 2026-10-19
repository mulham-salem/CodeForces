#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000009;

ll power(ll b, ll e, ll m) {
    ll r = 1; b %= m;
    while (e > 0) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k;
    cin >> n >> m >> k;
    ll w = n - m; // wrong answers
    ll t = (k - 1) * (w + 1); // max correct without doubling
    if (m <= t) {
        cout << m % MOD << "\n";
        return 0;
    }
    ll x = (m - t + k - 1) / k; // number of doublings
    ll p2 = power(2, x, MOD);
    ll ans = (2 * k % MOD) * ((p2 - 1 + MOD) % MOD) % MOD;
    ans = (ans + (m - x * k) % MOD + MOD) % MOD;
    cout << ans % MOD << "\n";
    return 0;
}
