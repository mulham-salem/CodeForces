#include <iostream>
#include <vector>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; i++)
        cin >> p[i].first >> p[i].second;

    DSU dsu(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].first == p[j].first || p[i].second == p[j].second)
                dsu.unite(i, j);
        }
    }

    int components = 0;

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i)
            components++;
    }

    cout << components - 1 << '\n';

    return 0;
}
