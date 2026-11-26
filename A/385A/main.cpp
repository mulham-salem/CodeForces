#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, c;
    cin >> n >> c;

    int x[100];

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int ans = 0;

    for (int i = 0; i < n - 1; i++) {

        int profit = x[i] - x[i + 1] - c;

        ans = max(ans, profit);
    }

    cout << ans << endl;

    return 0;
}
