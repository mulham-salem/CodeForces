#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long y, k, n;
    cin >> y >> k >> n;

    long long minSum = y + 1;

    if (minSum > n) {
        cout << -1;
        return 0;
    }

    bool found = false;

    for (long long sum = k; sum <= n; sum += k) {
        if (sum < minSum) continue;

        cout << sum - y << " ";
        found = true;
    }

    if (!found)
        cout << -1;

    return 0;
}
