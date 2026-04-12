#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
    long long g, s;
};

int parent_[205];

int find(int x) {
    return parent_[x] == x ? x : parent_[x] = find(parent_[x]);
}

bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent_[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    long long G, S;
    cin >> G >> S;

    vector<Edge> edges(M);
    for (int i = 0; i < M; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].g >> edges[i].s;
    }

    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.g < b.g;
    });

    vector<Edge> chosen;
    long long answer = LLONG_MAX;

    for (int i = 0; i < M; i++) {
        chosen.push_back(edges[i]);

        sort(chosen.begin(), chosen.end(), [](Edge a, Edge b) {
            return a.s < b.s;
        });

        vector<Edge> newChosen;

        for (int j = 1; j <= N; j++) parent_[j] = j;

        for (auto e : chosen) {
            if (unite(e.u, e.v)) {
                newChosen.push_back(e);
            }
        }

        chosen = newChosen;

        if ((int)chosen.size() == N - 1) {
            long long maxSilver = 0;
            for (auto e : chosen)
                maxSilver = max(maxSilver, e.s);

            long long cost = edges[i].g * G + maxSilver * S;
            answer = min(answer, cost);
        }
    }

    if (answer == LLONG_MAX) cout << -1 << '\n';
    else cout << answer << '\n';

    return 0;
}
