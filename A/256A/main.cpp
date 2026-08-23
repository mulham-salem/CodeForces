#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> b(n);

    for (int &x : b)
        cin >> x;

    // Coordinate compression
    vector<int> values = b;

    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    for (int &x : b) {
        x = lower_bound(values.begin(), values.end(), x) - values.begin();
    }

    int m = values.size();

    // dp[i][x] = longest valid subsequence ending at i,
    // where the previous value is x.
    vector<vector<short>> dp(n, vector<short>(m, 0));

    int answer = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int currentLength;

            if (dp[i][b[j]] == 0) {
                // b[i], b[j] starts a new progression
                currentLength = 2;
            } else {
                currentLength = dp[i][b[j]] + 1;
            }

            dp[j][b[i]] =
                max<int>(dp[j][b[i]], currentLength);

            answer = max(answer, currentLength);
        }
    }

    cout << answer << '\n';

    return 0;
}
