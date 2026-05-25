#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t1, t2, x1, x2, t0;
    cin >> t1 >> t2 >> x1 >> x2 >> t0;

    int bestY1 = 0, bestY2 = 0;

    for (int y2 = 0; y2 <= x2; y2++) {

        int y1;

        if (t0 == t1) {
            y1 = x1;
        } else {
            y1 = min(
                x1,
                (int)(1LL * y2 * (t2 - t0) / (t0 - t1))
            );
        }

        while (
            y1 > 0 &&
            1LL * y1 * t1 + 1LL * y2 * t2 <
            1LL * t0 * (y1 + y2)
        ) {
            y1--;
        }

        if (y1 + y2 == 0)
            continue;

        // temp = sum / total

        long long curNum =
            1LL * y1 * t1 + 1LL * y2 * t2;

        long long curDen =
            y1 + y2;

        long long bestNum =
            1LL * bestY1 * t1 + 1LL * bestY2 * t2;

        long long bestDen =
            bestY1 + bestY2;

        if (
            bestDen == 0 ||
            curNum * bestDen < bestNum * curDen ||
            (
                curNum * bestDen == bestNum * curDen &&
                curDen > bestDen
            )
        ) {
            bestY1 = y1;
            bestY2 = y2;
        }
    }

    cout << bestY1 << " " << bestY2 << '\n';

    return 0;
}
