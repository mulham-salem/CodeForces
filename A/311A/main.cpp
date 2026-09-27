#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long maxTot = n * (n - 1) / 2;

    if (maxTot <= k) {
        cout << "no solution\n";
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << 0 << " " << i << '\n';
    }

    return 0;
}
