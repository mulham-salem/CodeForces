#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 2005;

struct Node {
    int l, r, u, d;
};

Node p[MAXN][MAXN];
bool used[MAXN][MAXN];
int n, m, k;

// DSU Find Functions for 4 directions
int find_l(int x, int y) {
    if (y < 1) return 0;
    if (p[x][y].l == y) return y;
    return p[x][y].l = find_l(x, p[x][y].l);
}

int find_r(int x, int y) {
    if (y > m) return m + 1;
    if (p[x][y].r == y) return y;
    return p[x][y].r = find_r(x, p[x][y].r);
}

int find_u(int x, int y) {
    if (x < 1) return 0;
    if (p[x][y].u == x) return x;
    return p[x][y].u = find_u(p[x][y].u, y);
}

int find_d(int x, int y) {
    if (x > n) return n + 1;
    if (p[x][y].d == x) return x;
    return p[x][y].d = find_d(p[x][y].d, y);
}

// Update DSU links when a cell is taken
void mark(int x, int y) {
    used[x][y] = true;
    p[x][y].l = find_l(x, y - 1);
    p[x][y].r = find_r(x, y + 1);
    p[x][y].u = find_u(x - 1, y);
    p[x][y].d = find_d(x + 1, y);
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> n >> m >> k)) return 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            p[i][j] = {j, j, i, i};
        }
    }

    while (k--) {
        int x, y;
        cin >> x >> y;

        if (!used[x][y]) {
            mark(x, y);
            cout << x << " " << y << "\n";
            continue;
        }

        int best_x = -1, best_y = -1;
        int min_dist = 1e9;

        auto check = [&](int rx, int ry) {
            if (rx >= 1 && rx <= n && ry >= 1 && ry <= m && !used[rx][ry]) {
                int dist = abs(rx - x) + abs(ry - y);
                if (dist < min_dist ||
                   (dist == min_dist && (rx < best_x || (rx == best_x && ry < best_y)))) {
                    min_dist = dist;
                    best_x = rx;
                    best_y = ry;
                }
            }
        };

        for (int d = 0; d <= min_dist; ++d) {
            int r1 = x - d;
            int r2 = x + d;

            bool checked = false;

            if (r1 >= 1) {
                check(r1, find_l(r1, y));
                check(r1, find_r(r1, y));
                checked = true;
            }
            if (r2 <= n) {
                check(r2, find_l(r2, y));
                check(r2, find_r(r2, y));
                checked = true;
            }

            if (!checked && d > max(x, n - x + 1)) break;
        }

        mark(best_x, best_y);
        cout << best_x << " " << best_y << "\n";
    }

    return 0;
}
