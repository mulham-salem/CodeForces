#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double a, d;
    cin >> n >> a >> d;

    double lastArrival = 0.0;

    cout << fixed << setprecision(10);

    for (int i = 0; i < n; i++) {
        double t, v;
        cin >> t >> v;

        double travelTime;

        double sToMax = v * v / (2.0 * a);

        if (sToMax >= d) {
            // Never reaches maximum speed
            travelTime = sqrt(2.0 * d / a);
        } else {
            // Accelerate to v, then move at constant speed
            travelTime = v / a + (d - sToMax) / v;
        }

        double arrival = t + travelTime;

        arrival = max(arrival, lastArrival);

        cout << arrival << '\n';

        lastArrival = arrival;
    }

    return 0;
}
