#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ones = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        if (x == 1)
            ones++;
    }

    int negatives = n - ones;

    while (m--) {
        int l, r;
        cin >> l >> r;

        int len = r - l + 1;

        if (len % 2 == 1) {
            cout << 0 << '\n';
        } else {
            int need = len / 2;

            if (ones >= need && negatives >= need)
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
    }

    return 0;
}
