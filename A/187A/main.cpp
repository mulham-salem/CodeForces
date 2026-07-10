#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1), pos(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        pos[x] = i;
    }

    int i;
    for (i = 1; i < n; i++) {
        if (pos[a[i]] > pos[a[i + 1]])
            break;
    }

    cout << n - i << '\n';

    return 0;
}
