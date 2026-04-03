#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    // Gold from nothing
    if (d > 0 && c == 0) {
        cout << "Ron" << endl;
        return 0;
    }

    // Lead from nothing then gold
    if (b > 0 && a == 0 && d > 0 && c > 0) {
        cout << "Ron" << endl;
        return 0;
    }

    // Sand from nothing then gold
    if (f > 0 && e == 0 && b > 0 && a > 0 && d > 0 && c > 0) {
        cout << "Ron" << endl;
        return 0;
    }

    // Check profitable cycle (only if all non-zero to avoid division by zero)
    if (a > 0 && c > 0 && e > 0) {
        if (1LL * b * d * f > 1LL * a * c * e) {
            cout << "Ron" << endl;
            return 0;
        }
    }

    cout << "Hermione" << endl;
    return 0;
}
