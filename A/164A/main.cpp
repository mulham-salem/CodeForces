#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> f(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }

    vector<vector<int>> g(n + 1), rg(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    vector<int> fromAssign(n + 1, 0);
    queue<int> q;

    // Forward reachability from assignments
    for (int i = 1; i <= n; i++) {
        if (f[i] == 1) {
            fromAssign[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : g[u]) {
            if (f[v] == 1) continue; // cannot pass through another assignment

            if (!fromAssign[v]) {
                fromAssign[v] = 1;
                q.push(v);
            }
        }
    }

    vector<int> toUse(n + 1, 0);

    // Reverse reachability to uses
    for (int i = 1; i <= n; i++) {
        if (f[i] == 2) {
            toUse[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int p : rg[u]) {
            if (f[p] == 1) {
                if (!toUse[p]) {
                    toUse[p] = 1;
                }
                continue; // do not go beyond an assignment
            }

            if (!toUse[p]) {
                toUse[p] = 1;
                q.push(p);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (fromAssign[i] && toUse[i]);
        if (i < n) cout << '\n';
    }

    return 0;
}
