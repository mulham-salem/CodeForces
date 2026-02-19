#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (grid[i][j] != grid[i][0]) {
                cout << "NO";
                return 0;
            }
        }

        if (i > 0 && grid[i][0] == grid[i-1][0]) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
