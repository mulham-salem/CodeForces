#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;

    cin >> n >> k;

    vector<ll> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    ll d = 0;
    ll j = 0;

    for (int i = 0; i < n; i++) {

        ll t = j * (n - i - 1LL) * a[i];

        if (d - t < k) {
            cout << i + 1 << '\n';
        }
        else {
            d += j * a[i];
            j++;
        }
    }

    return 0;
}
