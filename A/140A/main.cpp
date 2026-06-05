#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, R, r;
    cin >> n >> R >> r;

    if (n == 1) {
        cout << (r <= R ? "YES" : "NO") << '\n';
        return 0;
    }

    if (R < r) {
        cout << "NO\n";
        return 0;
    }

    double d = R - r;
    double minDist = 2.0 * d * sin(acos(-1.0) / n);

    cout << (minDist + 1e-9 >= 2.0 * r ? "YES" : "NO") << '\n';

    return 0;
}
