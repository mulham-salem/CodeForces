#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;

    vector<int> q(m);
    for (int &x : q)
        cin >> x;

    int n;
    cin >> n;

    vector<long long> a(n);
    for (long long &x : a)
        cin >> x;

    sort(a.begin(), a.end());

    // Prefix Sum
    vector<long long> pref(n + 1, 0);

    for (int i = 0; i < n; i++)
        pref[i + 1] = pref[i] + a[i];

    // Remove duplicate discounts
    sort(q.begin(), q.end());
    q.erase(unique(q.begin(), q.end()), q.end());

    long long answer = pref[n];

    for (int x : q) {
        if (x > n)
            continue;

        long long cost = 0;
        int i = n;

        // Buy x items and get 2 items for free
        while (i >= x + 2) {
            cost += pref[i] - pref[i - x];
            i -= x + 2;
        }

        // If x + 1 items remain:
        // buy x and get 1 item for free
        if (i >= x + 1) {
            cost += pref[i] - pref[i - x];
            i = 0;
        }

        // Buy remaining items normally
        cost += pref[i];

        answer = min(answer, cost);
    }

    cout << answer << '\n';

    return 0;
}
