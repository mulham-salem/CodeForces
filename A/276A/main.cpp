#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;

    cin >> n >> k;

    long long maxJoy = -1e18;

    for (int i = 0; i < n; i++) {
        long long f, t;
        cin >> f >> t;

        long long joy;

        if (t <= k) {
            joy = f;
        } else {
            joy = f - (t - k);
        }

        maxJoy = max(maxJoy, joy);
    }

    cout << maxJoy << '\n';

    return 0;
}
