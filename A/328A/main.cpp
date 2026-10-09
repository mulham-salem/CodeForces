#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (b - a == c - b && c - b == d - c) {
        cout << d + (d - c) << endl;
    }
    else if (1LL * b * b == 1LL * a * c &&
             1LL * c * c == 1LL * b * d) {
        if (d * c % b == 0)
            cout << d * c / b << endl;
        else
            cout << 42 << endl;
    }
    else {
        cout << 42 << endl;
    }

    return 0;
}
