#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> files(m);
    vector<int> owner(n + 1, -1); // which file owns this cluster
    vector<int> posInFile(n + 1, -1); // position within file

    for (int i = 0; i < m; i++) {
        int ni;
        cin >> ni;
        files[i].resize(ni);
        for (int j = 0; j < ni; j++) {
            cin >> files[i][j];
            owner[files[i][j]] = i;
            posInFile[files[i][j]] = j;
        }
    }

    // Find free cluster
    int freeCluster = -1;
    for (int i = 1; i <= n; i++) {
        if (owner[i] == -1) {
            freeCluster = i;
            break;
        }
    }

    vector<pair<int, int>> ops;

    // Copy operation helper
    auto copyCluster = [&](int from, int to) {
        ops.push_back({from, to});
        owner[to] = owner[from];
        posInFile[to] = posInFile[from];
        files[owner[to]][posInFile[to]] = to;
        owner[from] = -1;
        posInFile[from] = -1;
    };

    int nextPos = 1;

    for (int f = 0; f < m; f++) {
        for (int j = 0; j < (int)files[f].size(); j++) {
            int expected = nextPos + j;
            int actual = files[f][j];

            if (actual == expected) continue;

            // If expected is occupied, move it to freeCluster
            if (owner[expected] != -1) {
                copyCluster(expected, freeCluster);
                freeCluster = expected;
            }

            // Now expected is free, move actual there
            copyCluster(actual, expected);
            freeCluster = actual;
        }
        nextPos += files[f].size();
    }

    cout << ops.size() << "\n";
    for (auto &op : ops) {
        cout << op.first << " " << op.second << "\n";
    }

    return 0;
}
