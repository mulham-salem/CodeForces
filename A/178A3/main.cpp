#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<long long> carry(n, 0);
    long long total_moves = 0;

    for (int i = 0; i < n - 1; i++) {
        if (i > 0) a[i] += carry[i];
        total_moves += a[i];
        cout << total_moves << '\n';

        // Move all units from position i to the furthest reachable position
        // For each unit, we can move it to i + 2^t for any t >= 0
        // To minimize future moves, we want to move to the furthest position
        int furthest = i;
        int step = 1;
        while (i + step * 2 < n) step *= 2;
        furthest = i + step;

        if (furthest < n) {
            carry[furthest] += a[i];
        }
    }

    return 0;
}
