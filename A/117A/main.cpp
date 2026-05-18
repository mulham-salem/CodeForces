#include <iostream>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll m;
    cin >> n >> m;

    ll cycle = 2 * (m - 1);

    while (n--) {
        ll s, f, t;
        cin >> s >> f >> t;

        // Already at destination
        if (s == f) {
            cout << t << '\n';
            continue;
        }

        ll waitTime;

        // Want to go upward
        if (s < f) {
            // Elevator reaches floor s while going up at time = s - 1
            ll first = s - 1;

            if (t <= first) {
                waitTime = first;
            } else {
                ll k = (t - first + cycle - 1) / cycle;
                waitTime = first + k * cycle;
            }

            cout << waitTime + (f - s) << '\n';
        }
        // Want to go downward
        else {
            // Elevator reaches floor s while going down at time:
            // (m - 1) + (m - s)
            ll first = (m - 1) + (m - s);

            if (t <= first) {
                waitTime = first;
            } else {
                ll k = (t - first + cycle - 1) / cycle;
                waitTime = first + k * cycle;
            }

            cout << waitTime + (s - f) << '\n';
        }
    }

    return 0;
}
