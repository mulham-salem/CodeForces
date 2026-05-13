#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;

    // n-1 numbers will be 1
    long long need = x - (n - 1);

    // smallest k which k^2 >= need
    long long k = ceil(sqrt((double)max(1LL, need)));

    // check sum condition
    if (k + (n - 1) > y) {
        cout << -1 << endl;
        return 0;
    }

    cout << k << endl;

    for (int i = 1; i < n; i++) {
        cout << 1 << endl;
    }

    return 0;
}
