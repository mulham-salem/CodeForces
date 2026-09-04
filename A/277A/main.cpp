#include <bits/stdc++.h>
using namespace std;

class DSU {
private:
    vector<int> parent, sz;

public:
    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    vector<vector<int>> language(m);

    bool allZero = true;

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        if (k > 0)
            allZero = false;

        for (int j = 0; j < k; j++) {
            int lang;
            cin >> lang;

            lang--;

            language[lang].push_back(i);
        }
    }

    // Connect employees who know the same language
    for (int lang = 0; lang < m; lang++) {
        for (int i = 1; i < language[lang].size(); i++) {
            dsu.unite(language[lang][0], language[lang][i]);
        }
    }

    // Count connected components
    int components = 0;

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            components++;
        }
    }

    if (allZero)
        cout << n << '\n';
    else
        cout << components - 1 << '\n';

    return 0;
}
