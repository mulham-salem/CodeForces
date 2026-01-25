#include <bits/stdc++.h>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    int maxCorrect = 0, minCorrect = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        maxCorrect = max(maxCorrect, a[i]);
        minCorrect = min(minCorrect, a[i]);
    }

    int minWrong = INT_MAX;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        minWrong = min(minWrong, b[i]);
    }

    int v = max(maxCorrect, 2*minCorrect);

    if (v < minWrong)
        cout << v;
    else
        cout << -1;

    return 0;
}
