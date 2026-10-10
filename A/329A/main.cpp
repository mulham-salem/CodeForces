#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    vector<pair<int, int>> ans;
    bool possible = true;

    // Try to choose one cell from each row
    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '.') {
                ans.push_back({i + 1, j + 1});
                found = true;
                break;
            }
        }

        if (!found) {
            possible = false;
            break;
        }
    }

    if (possible) {
        for (auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
        return 0;
    }

    // If some row has no '.', try each column
    ans.clear();
    possible = true;

    for (int j = 0; j < n; j++) {
        bool found = false;

        for (int i = 0; i < n; i++) {
            if (grid[i][j] == '.') {
                ans.push_back({i + 1, j + 1});
                found = true;
                break;
            }
        }

        if (!found) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
    } else {
        for (auto p : ans) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}
