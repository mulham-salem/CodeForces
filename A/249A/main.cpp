#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double y1, y2, yw, xb, yb, r;
    cin >> y1 >> y2 >> yw >> xb >> yb >> r;

    // Move the wall inward by r because the ball has radius r.
    yw -= r;

    // Reflect the ball across the effective wall.
    yb = 2.0L * yw - yb;

    // Move the lower goal post inward by r.
    y1 += r;

    // Aim at the lower safe point of the goal.
    long double xw =
        xb * (yw - y1) / (yb - y1);

    /*
        Check whether the line from the reflected ball
        to the lower safe goal point gets too close to
        the upper goal post.

        Distance^2 from point (0, y2) to the line:
            (xb, yb) -> (0, y1)

        If this distance is at least r, the ball
        does not touch the upper post.
    */
    long double dy = yb - y1;
    long double dx = xb;

    long double numerator = xb * (y1 - y2);
    long double denominator = xb * xb + dy * dy;

    long double dist2 =
        numerator * numerator / denominator;

    const long double EPS = 1e-12L;

    if (dist2 + EPS >= r * r) {
        cout << fixed << setprecision(15) << xw << '\n';
    } else {
        cout << -1 << '\n';
    }

    return 0;
}
