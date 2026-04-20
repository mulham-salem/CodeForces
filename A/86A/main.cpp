#include <iostream>
#include <algorithm>
using namespace std;

long long reflect(long long n) {
    if (n == 0) return 0;
    long long res = 0;
    long long mul = 1;
    while (n > 0) {
        int d = n % 10;
        res += (9 - d) * mul;
        mul *= 10;
        n /= 10;
    }
    return res;
}

int main() {
    long long l, r;
    cin >> l >> r;

    long long ans = max(l * reflect(l), r * reflect(r));

    // a * 10^m - 1
    for (int a = 1; a <= 9; a++) {
        long long p = 1;
        while (true) {
            long long candidate = a * p - 1;
            if (candidate > r) break;
            if (candidate >= l) {
                ans = max(ans, candidate * reflect(candidate));
            }
            p *= 10;
        }
    }

    cout << ans << endl;

    return 0;
}
