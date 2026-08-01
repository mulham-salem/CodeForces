#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    cout << (a + b - 1) * (a + c - 1) - a * (a - 1);

    return 0;
}
