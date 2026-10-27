#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int z = 0;
    int m = 0;
    double sumFrac = 0;

    for (int i = 0; i < 2 * n; i++) {
        double a;
        cin >> a;
        double frac = a - floor(a);
        if (frac < 1e-9) {
            z++;
        } else {
            m++;
            sumFrac += frac;
        }
    }

    int lo = max(0, n - z);
    int hi = min(n, m);

    double best = 1e18;
    for (int c = lo; c <= hi; c++) {
        best = min(best, fabs(c - sumFrac));
    }

    cout << fixed << setprecision(3) << best << "\n";
    return 0;
}
