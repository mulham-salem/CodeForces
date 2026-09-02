#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    unordered_set<long long> chosen;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        long long x = a[i];

        if (x % k != 0) {
            chosen.insert(x);
            ans++;
        }

        else {
            if (chosen.find(x / k) == chosen.end()) {
                chosen.insert(x);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
