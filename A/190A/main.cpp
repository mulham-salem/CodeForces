#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    if (n == 0 && m > 0) {
        cout << "Impossible";
        return 0;
    }

    // Minimum: maximize number of free children
    long long minimum = n + max(0LL, m - n);

    // Maximum: minimize number of adults carrying children
    long long maximum;

    if (m == 0)
        maximum = n;
    else
        maximum = n + m - 1;

    cout << minimum << " " << maximum;

    return 0;
}
