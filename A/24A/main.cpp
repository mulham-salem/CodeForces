#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int from;
    int to;
    int cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<Edge> edges;

    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        edges.push_back({a, b, c});
    }

    vector<vector<int>> adj(n + 1);

    for (auto &e : edges) {
        adj[e.from].push_back(e.to);
        adj[e.to].push_back(e.from);
    }

    vector<int> order;
    vector<bool> visited(n + 1, false);

    int start = 1;
    int prev = -1;
    int curr = start;

    while (true) {
        order.push_back(curr);
        visited[curr] = true;

        for (int neighbor : adj[curr]) {
            if (neighbor != prev) {
                prev = curr;
                curr = neighbor;
                break;
            }
        }

        if (curr == start)
            break;
    }

    auto computeCost = [&](vector<int> ring) {
        int total = 0;

        for (int i = 0; i < n; i++) {
            int u = ring[i];
            int v = ring[(i + 1) % n];

            for (auto &e : edges) {
                if (e.from == u && e.to == v) {
                    break;
                }
                if (e.from == v && e.to == u) {
                    total += e.cost;
                    break;
                }
            }
        }

        return total;
    };

    int cost1 = computeCost(order);

    reverse(order.begin(), order.end());
    int cost2 = computeCost(order);

    cout << min(cost1, cost2) << "\n";
    return 0;
}
