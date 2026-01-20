#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> cnt(8, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    vector<array<int, 3>> result;

    int g = min({cnt[1], cnt[3], cnt[6]});
    for (int i = 0; i < g; i++) {
        result.push_back({1, 3, 6});
    }
    cnt[1] -= g;
    cnt[3] -= g;
    cnt[6] -= g;

    g = min({cnt[1], cnt[2], cnt[4]});
    for (int i = 0; i < g; i++) {
        result.push_back({1, 2, 4});
    }
    cnt[1] -= g;
    cnt[2] -= g;
    cnt[4] -= g;

    g = min({cnt[1], cnt[2], cnt[6]});
    for (int i = 0; i < g; i++) {
        result.push_back({1, 2, 6});
    }
    cnt[1] -= g;
    cnt[2] -= g;
    cnt[6] -= g;

    if ((int)result.size() != n / 3) {
        cout << -1 << "\n";
        return 0;
    }

    for (auto &grp : result) {
        cout << grp[0] << " " << grp[1] << " " << grp[2] << "\n";
    }

    return 0;
}
