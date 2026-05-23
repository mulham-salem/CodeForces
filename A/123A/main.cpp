#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();

    vector<int> group;
    vector<bool> used(n + 1, false);

    // Find all positions that must contain the same character
    for (int p = 2; p <= n; p++) {
        bool prime = true;

        for (int i = 2; i * i <= p; i++) {
            if (p % i == 0) {
                prime = false;
                break;
            }
        }

        if (!prime) continue;

        if (p <= n / 2) {
            for (int j = p; j <= n; j += p) {
                if (!used[j]) {
                    used[j] = true;
                    group.push_back(j);
                }
            }
        }
    }

    vector<int> freq(26, 0);

    for (char c : s)
        freq[c - 'a']++;

    int best = max_element(freq.begin(), freq.end()) - freq.begin();

    // Need enough copies for all linked positions
    if (freq[best] < group.size()) {
        cout << "NO\n";
        return 0;
    }

    string ans(n, '?');

    // Fill linked positions
    for (int pos : group) {
        ans[pos - 1] = char(best + 'a');
        freq[best]--;
    }

    // Fill remaining positions
    for (int i = 0; i < n; i++) {
        if (ans[i] == '?') {
            for (int j = 0; j < 26; j++) {
                if (freq[j] > 0) {
                    ans[i] = char(j + 'a');
                    freq[j]--;
                    break;
                }
            }
        }
    }

    cout << "YES\n";
    cout << ans << '\n';

    return 0;
}
