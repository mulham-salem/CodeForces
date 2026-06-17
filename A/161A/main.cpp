#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long x, y;
    cin >> n >> m >> x >> y;

    vector<long long> a(n + 1), b(m + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];

    vector<pair<int, int>> ans;

    int i = 1, j = 1;

    while (i <= n && j <= m) {
        if (b[j] < a[i] - x) {
            j++;
        } else if (b[j] > a[i] + y) {
            i++;
        } else {
            ans.push_back({i, j});
            i++;
            j++;
        }
    }

    cout << ans.size() << '\n';

    for (auto &[u, v] : ans) {
        cout << u << ' ' << v << '\n';
    }

    return 0;
}
