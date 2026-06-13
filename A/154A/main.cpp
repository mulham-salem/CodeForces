#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int k;
    cin >> k;

    bool forbidden[26][26] = {};

    for (int i = 0; i < k; i++) {
        string p;
        cin >> p;

        int a = p[0] - 'a';
        int b = p[1] - 'a';

        forbidden[a][b] = forbidden[b][a] = true;
    }

    int n = (int)s.size();

    vector<int> dp(27, INF), ndp(27, INF);

    // state 26 = no character kept yet
    dp[26] = 0;

    for (char ch : s) {
        int cur = ch - 'a';

        fill(ndp.begin(), ndp.end(), INF);

        for (int last = 0; last <= 26; last++) {
            if (dp[last] == INF) continue;

            // delete current character
            ndp[last] = min(ndp[last], dp[last] + 1);

            // keep current character
            if (last == 26 || !forbidden[last][cur]) {
                ndp[cur] = min(ndp[cur], dp[last]);
            }
        }

        dp.swap(ndp);
    }

    cout << *min_element(dp.begin(), dp.end()) << '\n';

    return 0;
}
