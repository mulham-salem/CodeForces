#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    long long d = abs(x) + abs(y);

    if (x > 0 && y > 0) {
        // First quadrant
        cout << 0 << " " << d << " " << d << " " << 0 << endl;
    } else if (x < 0 && y > 0) {
        // Second quadrant
        cout << -d << " " << 0 << " " << 0 << " " << d << endl;
    } else if (x < 0 && y < 0) {
        // Third quadrant
        cout << -d << " " << 0 << " " << 0 << " " << -d << endl;
    } else {
        // Fourth quadrant (x > 0, y < 0)
        cout << 0 << " " << -d << " " << d << " " << 0 << endl;
    }

    return 0;
}
