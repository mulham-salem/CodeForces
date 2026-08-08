#include <bits/stdc++.h>
using namespace std;

long long C3(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}

long long C2(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    long long k;
    cin >> k;

    const int MAXN = 100;

    vector<vector<int>> g(MAXN, vector<int>(MAXN, 0));

    // Try every possible size of the main clique
    for (int clique = 3; clique <= MAXN; clique++) {

        long long remaining = k - C3(clique);

        if (remaining < 0)
            continue;

        int n = clique;
        bool possible = true;

        // The first 'clique' vertices form a complete graph
        for (int i = 0; i < clique; i++) {
            for (int j = i + 1; j < clique; j++) {
                g[i][j] = 1;
                g[j][i] = 1;
            }
        }

        // Represent remaining as a sum of C(m, 2)
        while (remaining > 0) {

            if (n >= MAXN) {
                possible = false;
                break;
            }

            // Find largest m such that C(m,2) <= remaining
            int m = 2;

            while (m + 1 <= clique &&
                   C2(m + 1) <= remaining) {
                m++;
            }

            // New vertex
            // Connect it to the first m vertices of the clique
            for (int j = 0; j < m; j++) {
                g[n][j] = 1;
                g[j][n] = 1;
            }

            remaining -= C2(m);
            n++;
        }

        if (possible) {
            cout << n << '\n';

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cout << g[i][j];
                }
                cout << '\n';
            }

            return 0;
        }

        // Reset graph before trying another clique size
        g.assign(MAXN, vector<int>(MAXN, 0));
    }

    return 0;
}
