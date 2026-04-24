#include <iostream>
using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;

    int t = 0;

    while (r > 0 || g > 0 || b > 0) {
        if (t % 3 == 0) {
            // Red
            int take = min(2, r);
            r -= take;
        } else if (t % 3 == 1) {
            // Green
            int take = min(2, g);
            g -= take;
        } else {
            // Blue
            int take = min(2, b);
            b -= take;
        }
        t++;
    }

    cout << (t - 1 + 30) << endl;

    return 0;
}
