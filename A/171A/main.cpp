#include <iostream>
using namespace std;

int main() {
    long long a1, a2;
    cin >> a1 >> a2;

    long long rev = 0;

    while (a2 > 0) {
        rev = rev * 10 + a2 % 10;
        a2 /= 10;
    }

    cout << a1 + rev << '\n';

    return 0;
}
