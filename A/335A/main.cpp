#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;
    int n;
    cin >> n;

    // Count frequencies
    map<char, int> cnt;
    for (char c : s) cnt[c]++;

    int distinct = cnt.size();

    // Feasibility check
    if (distinct > n) {
        cout << -1 << endl;
        return 0;
    }

    // Binary search for minimum k
    int lo = 1, hi = s.size(); // k can't exceed |s| (each sheet gives at least 1 of each needed char)
    int best_k = hi;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        // Check if k = mid is feasible: sum of ceil(cnt[c]/mid) <= n
        long long needed = 0;
        for (auto &p : cnt) {
            needed += (p.second + mid - 1) / mid; // ceil division
        }
        if (needed <= n) {
            best_k = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    int k = best_k;

    // Construct sheet
    string sheet = "";
    for (auto &p : cnt) {
        int x = (p.second + k - 1) / k; // ceil(cnt/k)
        for (int i = 0; i < x; i++) sheet += p.first;
    }
    // Fill remaining slots
    while ((int)sheet.size() < n) sheet += 'a';
    // Sort for neatness (optional)
    sort(sheet.begin(), sheet.end());

    cout << k << "\n" << sheet << "\n";

    return 0;
}
