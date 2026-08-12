#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, k;
    cin >> m >> k;

    vector<int> d(m), s(m);

    for (int i = 0; i < m; i++)
        cin >> d[i];

    for (int i = 0; i < m; i++)
        cin >> s[i];

    long long fuel = s[0];
    long long maxFuel = s[0];
    long long answer = 0;

    for (int i = 0; i < m; i++) {

        maxFuel = max(maxFuel, (long long)s[i]);

        // We need more fuel to cross this road.
        if (fuel < d[i]) {
            long long need = d[i] - fuel;

            // Number of additional refills needed.
            long long batches = (need + maxFuel - 1) / maxFuel;

            fuel += batches * maxFuel;
            answer += batches * k;
        }

        // Travel through the road.
        fuel -= d[i];
        answer += d[i];

        // On arrival, the next city's fuel is transferred immediately.
        if (i + 1 < m) {
            fuel += s[i + 1];
        }
    }

    cout << answer << '\n';

    return 0;
}
