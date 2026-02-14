#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, p1, p2, p3, t1, t2;
    cin >> n >> p1 >> p2 >> p3 >> t1 >> t2;

    vector<pair<int, int>> v;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        v.push_back({l, r});
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        int working_time = v[i].second - v[i].first;
        ans += working_time * p1;

        if (i > 0) {
            int interval_tiem = v[i].first - v[i-1].second;

            int normalTime = min(interval_tiem, t1);
            ans += normalTime * p1;
            interval_tiem -= normalTime;

            int screenTime = min(interval_tiem, t2);
            ans += screenTime * p2;
            interval_tiem -= screenTime;

            ans += interval_tiem * p3;
        }
    }

    cout << ans;

    return 0;
}
