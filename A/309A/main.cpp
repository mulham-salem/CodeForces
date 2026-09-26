#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long l, t;

    cin >> n >> l >> t;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long x = 2LL * t;

    long long q = x / l;
    long long r = x % l;

    long long pairs = 1LL * n * (n - 1) / 2;

    long long closePairs = 0;

    if (r > 0) {
        vector<long long> b(2 * n);

        for (int i = 0; i < n; i++) {
            b[i] = a[i];
            b[i + n] = a[i] + l;
        }

        int j = 1;

        for (int i = 0; i < n; i++) {

            if (j < i + 1)
                j = i + 1;

            while (j < i + n && b[j] - b[i] <= r)
                j++;

            closePairs += j - i - 1;
        }
    }

    long double answer =
        (long double)pairs * q / 2.0L
        + (long double)closePairs / 4.0L;

    cout << fixed << setprecision(10) << answer << '\n';

    return 0;
}
