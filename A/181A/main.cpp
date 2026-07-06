#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int x = 0, y = 0;

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for (int j = 1; j <= m; j++) {
            if (s[j - 1] == '*') {
                x ^= i;  // XOR rows
                y ^= j;  // XOR cols
            }
        }
    }

    cout << x << " " << y << "\n";
    return 0;
}
