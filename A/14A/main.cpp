#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int min_row = n, min_col = m;
    int max_row = -1, max_col = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                min_row = min(min_row, i);
                max_row = max(max_row, i);
                min_col = min(min_col, j);
                max_col = max(max_col, j);
            }
        }
    }

    for (int i = min_row; i <= max_row; i++) {
        for (int j = min_col; j <= max_col; j++) {
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
