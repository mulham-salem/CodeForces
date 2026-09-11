#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 4 == 2 || n % 4 == 3) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> p(n + 1, 0);

    if (n % 4 == 1) {
        int m = (n + 1) / 2;
        p[m] = m;
    }

    for (int a = 1; a <= n; a++) {
        if (p[a] != 0) continue;
        int b = n - a + 1;
        if (p[b] != 0) continue;
        // find next unassigned x > a, x != b
        int x = a + 1;
        while (x <= n && (p[x] != 0 || x == b)) x++;
        int y = n - x + 1;
        p[a] = x;
        p[x] = b;
        p[b] = y;
        p[y] = a;
    }

    for (int i = 1; i <= n; i++) {
        cout << p[i];
        if (i < n) cout << " ";
    }
    cout << endl;

    return 0;
}
