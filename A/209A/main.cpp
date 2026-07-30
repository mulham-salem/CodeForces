#include <iostream>
using namespace std;

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long a = 0, b = 0;

    while (n--) {
        if (n & 1)
            a = (a + b + 1) % MOD;
        else
            b = (a + b + 1) % MOD;
    }

    cout << (a + b) % MOD << '\n';

    return 0;
}
