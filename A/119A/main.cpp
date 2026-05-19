#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    while (true) {

        // Simon's turn
        int g = __gcd(a, n);

        if (n < g) {
            cout << 1 << endl;
            break;
        }

        n -= g;

        // Antisimon's turn
        g = __gcd(b, n);

        if (n < g) {
            cout << 0 << endl;
            break;
        }

        n -= g;
    }

    return 0;
}
