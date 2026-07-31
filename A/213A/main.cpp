#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int n;
int c[N], indeg[N], backup[N];
vector<int> g[N];

int solve(int start) {
    memcpy(backup, indeg, sizeof(indeg));

    queue<int> q[4];

    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0)
            q[c[i]].push(i);

    int cur = start;
    int ans = 0;

    while (!q[1].empty() || !q[2].empty() || !q[3].empty()) {

        while (!q[cur].empty()) {
            int u = q[cur].front();
            q[cur].pop();
            ans++;                  // finish one task

            for (int v : g[u]) {
                if (--indeg[v] == 0)
                    q[c[v]].push(v);
            }
        }

        cur = cur % 3 + 1;          // move to next computer
        ans++;                      // movement cost = 1
    }

    memcpy(indeg, backup, sizeof(indeg));

    return ans - 1;                 // last move is unnecessary
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> c[i];

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            g[x].push_back(i);
            indeg[i]++;
        }
    }

    int ans = INT_MAX;

    for (int s = 1; s <= 3; s++)
        ans = min(ans, solve(s));

    cout << ans << '\n';
}
