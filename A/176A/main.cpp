#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int profit;
    int cnt;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> buy(n, vector<int>(m));
    vector<vector<int>> sell(n, vector<int>(m));
    vector<vector<int>> cnt(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        for (int j = 0; j < m; j++) {
            cin >> buy[i][j] >> sell[i][j] >> cnt[i][j];
        }
    }

    int ans = 0;

    for (int from = 0; from < n; from++) {
        for (int to = 0; to < n; to++) {
            if (from == to) continue;

            vector<Item> items;

            for (int t = 0; t < m; t++) {
                int p = sell[to][t] - buy[from][t];
                if (p > 0)
                    items.push_back({p, cnt[from][t]});
            }

            sort(items.begin(), items.end(), [](Item a, Item b) {
                return a.profit > b.profit;
            });

            int remain = k;
            int curProfit = 0;

            for (auto x : items) {
                int take = min(remain, x.cnt);
                curProfit += take * x.profit;
                remain -= take;
                if (remain == 0) break;
            }

            ans = max(ans, curProfit);
        }
    }

    cout << ans << '\n';

    return 0;
}
