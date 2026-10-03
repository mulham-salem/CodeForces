#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y, m;
    cin >> x >> y >> m;

    if (x >= m || y >= m) {
        cout << 0 << '\n';
        return 0;
    }

    if (x <= 0 && y <= 0) {
        cout << -1 << '\n';
        return 0;
    }

    long long ans = 0;

    while (x < m && y < m) {
        if (x <= 0) {
            long long k = (-x) / y + 1;
            x += k * y;
            ans += k;
        } else if (y <= 0) {
            long long k = (-y) / x + 1;
            y += k * x;
            ans += k;
        } else if (x < y) {
            x += y;
            ans++;
        } else {
            y += x;
            ans++;
        }
    }

    cout << ans << '\n';
    return 0;
}
