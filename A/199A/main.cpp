#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << "0 0 0\n";
        return 0;
    }
    if (n == 1) {
        cout << "0 0 1\n";
        return 0;
    }

    long long a = 0, b = 1;
    while (b < n) {
        long long c = a + b;
        a = b;
        b = c;
    }

    cout << a << " " << (b - a) << " " << "0\n";
    return 0;
}
