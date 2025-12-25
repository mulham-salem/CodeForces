#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int l_open = 0, l_close = 0, r_open = 0, r_close = 0;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;

        if (l == 0) l_close++;
        else l_open++;

        if (r == 0) r_close++;
        else r_open++;
    }

    int res = 0;

    res += min(l_open, l_close);
    res += min(r_open, r_close);

    cout << res;

    return 0;
}
