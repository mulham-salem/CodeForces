#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a_received = 0, a_pings = 0;
    int b_received = 0, b_pings = 0;

    for (int i = 0; i < n; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            a_received += x;
            a_pings++;
        } else {
            b_received += x;
            b_pings++;
        }
    }

    if (a_received >= a_pings * 5)
        cout << "LIVE\n";
    else
        cout << "DEAD\n";

    if (b_received >= b_pings * 5)
        cout << "LIVE\n";
    else
        cout << "DEAD\n";

    return 0;
}
