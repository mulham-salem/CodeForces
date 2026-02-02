#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector <pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        int p, t;
        cin >> p >> t;

        v.push_back({p, t});
    }

    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first)
                return a.first > b.first;
            return a.second < b.second;
         });

    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first == v[k-1].first &&
            v[i].second == v[k-1].second) {
                ans++;
            }
    }

    cout << ans;

    return 0;
}
