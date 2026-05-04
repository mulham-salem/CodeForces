#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int k;
    cin >> k;

    // Count frequency
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Store (frequency, character)
    vector<pair<int, char>> v;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            v.push_back({freq[i], char('a' + i)});
        }
    }

    // Sort by frequency ascending
    sort(v.begin(), v.end());

    // Mark removed characters
    vector<bool> removed(26, false);

    for (auto &p : v) {
        int f = p.first;
        char c = p.second;

        if (f <= k) {
            k -= f;
            removed[c - 'a'] = true;
        } else {
            break;
        }
    }

    // Build result string (subsequence)
    string result = "";
    for (char c : s) {
        if (!removed[c - 'a']) {
            result += c;
        }
    }

    // Count distinct remaining characters
    vector<bool> exist(26, false);
    for (char c : result) {
        exist[c - 'a'] = true;
    }

    int m = 0;
    for (bool e : exist) {
        if (e) m++;
    }

    cout << m << "\n";
    cout << result << "\n";

    return 0;
}
