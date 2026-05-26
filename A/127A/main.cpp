#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    double x[105], y[105];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    double totalLength = 0.0;

    for (int i = 1; i < n; i++) {
        double dx = x[i] - x[i - 1];
        double dy = y[i] - y[i - 1];

        totalLength += sqrt(dx * dx + dy * dy);
    }

    double totalTime = (totalLength * k) / 50.0;

    cout << fixed << setprecision(9) << totalTime << '\n';

    return 0;
}
