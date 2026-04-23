#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    long long m, k;
    cin >> n >> m >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    if (n % 2 == 0 || n == 1) {
        // For even n or n=1, check special cases
        if (n == 1) {
            // He can take all diamonds in first minute
            cout << min(a[0], m * k) << endl;
        } else {
            // For even n, it's impossible to take any diamond
            cout << 0 << endl;
        }
        return 0;
    }

    // n is odd and n > 1
    long long minOdd = a[0];
    for (int i = 2; i < n; i += 2) {
        minOdd = min(minOdd, a[i]);
    }

    long long opsPerMinute = m / ((n + 1) / 2);
    long long maxTake = min(minOdd, opsPerMinute * k);

    cout << maxTake << endl;

    return 0;
}
