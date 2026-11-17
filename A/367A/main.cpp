#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int n = s.size();

    vector<int> prefX(n + 1, 0);
    vector<int> prefY(n + 1, 0);
    vector<int> prefZ(n + 1, 0);

    for (int i = 1; i <= n; i++) {

        prefX[i] = prefX[i - 1];
        prefY[i] = prefY[i - 1];
        prefZ[i] = prefZ[i - 1];

        if (s[i - 1] == 'x') {
            prefX[i]++;
        }
        else if (s[i - 1] == 'y') {
            prefY[i]++;
        }
        else {
            prefZ[i]++;
        }
    }

    int m;
    cin >> m;

    while (m--) {

        int l, r;
        cin >> l >> r;

        if (r - l + 1 < 3) {
            cout << "YES\n";
            continue;
        }

        int x = prefX[r] - prefX[l - 1];
        int y = prefY[r] - prefY[l - 1];
        int z = prefZ[r] - prefZ[l - 1];

        int mx = max({x, y, z});
        int mn = min({x, y, z});

        if (mx - mn <= 1) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
