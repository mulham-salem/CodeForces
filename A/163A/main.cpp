#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    int n = s.size();
    int m = t.size();

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    long long ans = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1];

            if (s[i - 1] == t[j - 1]) {
                long long add = (1 + dp[i - 1][j - 1]) % MOD;

                dp[i][j] = (dp[i][j] + add) % MOD;
                ans = (ans + add) % MOD;
            }
        }
    }

    cout << ans % MOD << '\n';
    return 0;
}
