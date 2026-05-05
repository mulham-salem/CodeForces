#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> price(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    vector<unordered_set<int>> adj(n + 1);
    vector<pair<int, int>> edges;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
        edges.push_back({u, v});
    }

    int ans = INT_MAX;

    for (auto [u, v] : edges) {
        // iterate over smaller adjacency set
        if (adj[u].size() > adj[v].size()) {
            swap(u, v);
        }

        for (int w : adj[u]) {
            if (w == v) continue;

            if (adj[v].count(w)) {
                int cost = price[u] + price[v] + price[w];
                ans = min(ans, cost);
            }
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }

    return 0;
}
