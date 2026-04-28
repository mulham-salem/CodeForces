#include <iostream>

using namespace std;

int main() {
    long long n, m, a, b;
    cin >> n >> m >> a >> b;

    long long r1 = (a - 1) / m;
    long long c1 = (a - 1) % m;
    long long r2 = (b - 1) / m;
    long long c2 = (b - 1) % m;

    if (b == n) {
        c2 = m - 1;
    }

    if (r1 == r2) {
        cout << 1 << endl;
    }

    else if (c1 == 0 && c2 == m - 1) {
        cout << 1 << endl;
    }

    else if (r2 - r1 == 1) {
        cout << 2 << endl;
    }

    else if (c1 == 0 || c2 == m - 1 || c1 == c2 + 1) {
        cout << 2 << endl;
    }

    else {
        cout << 3 << endl;
    }

    return 0;
}
