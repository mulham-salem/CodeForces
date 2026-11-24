#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    long long ones = 0;
    long long ans = 0;

    for (int i = 0; i < n; i++) {

        int x;
        cin >> x;

        if (x == 1) {
            ones++;
        }
        else {
            ans += ones;
        }
    }

    cout << ans << endl;

    return 0;
}
