#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long k, b, n, t;
    if (!(cin >> k >> b >> n >> t)) return 0;

    long long current = 1;
    long long seconds_to_reach_t = 0;

    while (current <= t && seconds_to_reach_t < n) {
        current = k * current + b;
        seconds_to_reach_t++;
    }

    if (current > t) {
        cout << n - seconds_to_reach_t + 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}
