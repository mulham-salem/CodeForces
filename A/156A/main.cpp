#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, u;
    cin >> s >> u;

    int n = s.size();
    int m = u.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int best = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j - 1] + (s[i - 1] == u[j - 1]);

            best = max(best, dp[i][j]);
        }
    }

    cout << m - best << '\n';
    return 0;
}
