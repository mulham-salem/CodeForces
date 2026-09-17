#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> l(m + 1), r(m + 1);
    vector<long long> d(m + 1);

    for (int i = 1; i <= m; i++)
        cin >> l[i] >> r[i] >> d[i];

    // Difference array for queries
    vector<long long> diffOps(m + 2, 0);

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;

        diffOps[x]++;
        diffOps[y + 1]--;
    }

    // Calculate how many times each operation is executed
    long long times = 0;

    for (int i = 1; i <= m; i++) {
        times += diffOps[i];
        d[i] *= times;
    }

    // Difference array for the original array
    vector<long long> diffArray(n + 2, 0);

    for (int i = 1; i <= m; i++) {
        diffArray[l[i]] += d[i];
        diffArray[r[i] + 1] -= d[i];
    }

    // Apply all operations to a
    long long add = 0;

    for (int i = 1; i <= n; i++) {
        add += diffArray[i];
        a[i] += add;
    }

    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';

    cout << '\n';

    return 0;
}
