#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

vector<ll> lucky;

// Generate all lucky numbers
void generate(ll num) {
    if (num > 10000000000LL)
        return;

    if (num != 0)
        lucky.push_back(num);

    generate(num * 10 + 4);
    generate(num * 10 + 7);
}

int main() {
    ll l, r;
    cin >> l >> r;

    generate(0);

    sort(lucky.begin(), lucky.end());

    ll sum = 0;
    ll current = l;

    for (ll x : lucky) {
        if (x < current)
            continue;

        ll end = min(r, x);

        sum += (end - current + 1) * x;

        current = end + 1;

        if (current > r)
            break;
    }

    cout << sum << endl;

    return 0;
}
