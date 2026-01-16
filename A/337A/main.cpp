#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];

    sort(p.begin(), p.end());

    int ans = INT_MAX;

    for (int i = 0; i <= m-n; i++) {
        int diff = p[i + n - 1] - p[i];
        ans = min(ans, diff);
    }

    cout << ans;


    return 0;
}
