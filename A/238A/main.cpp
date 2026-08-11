#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1000000009LL;

ll modPow(ll base, ll exp) {
    ll result = 1;

    while (exp > 0) {
        if (exp & 1)
            result = result * base % MOD;

        base = base * base % MOD;
        exp >>= 1;
    }

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // If 2^m <= n, we cannot have n+1 distinct prefix XORs.
    if (m <= 16 && (1 << m) <= n) {
        cout << 0 << '\n';
        return 0;
    }

    ll x = modPow(2, m);

    ll answer = 1;

    for (int i = 1; i <= n; i++) {
        answer = answer * (x - i) % MOD;

        if (answer < 0)
            answer += MOD;
    }

    cout << answer << '\n';

    return 0;
}
