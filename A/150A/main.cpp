#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long q;
    cin >> q;

    vector<long long> factors;
    long long n = q;

    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    if (n > 1)
        factors.push_back(n);

    if (factors.size() < 2) {
        cout << 1 << '\n' << 0 << '\n';
    } else if (factors.size() == 2) {
        cout << 2 << '\n';
    } else {
        cout << 1 << '\n';
        cout << factors[0] * factors[1] << '\n';
    }

    return 0;
}
