#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int NEG = -1000000000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int dp[26][26];

    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            dp[i][j] = NEG;

    while (n--) {
        string s;
        cin >> s;

        int first = s.front() - 'a';
        int last = s.back() - 'a';
        int len = s.size();

        int old[26][26];
        for (int i = 0; i < 26; i++)
            for (int j = 0; j < 26; j++)
                old[i][j] = dp[i][j];

        // Start a new dynasty
        dp[first][last] = max(dp[first][last], len);

        // Extend existing dynasties
        for (int start = 0; start < 26; start++) {
            if (old[start][first] == NEG)
                continue;

            dp[start][last] =
                max(dp[start][last], old[start][first] + len);
        }
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = max(ans, dp[i][i]);

    cout << ans << '\n';

    return 0;
}
