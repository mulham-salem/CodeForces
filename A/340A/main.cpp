#include <iostream>
#include <numeric>
using namespace std;

int main() {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;

    long long lcm = (x / gcd(x, y)) * y;
    long long ans = b / lcm - (a - 1) / lcm;

    cout << ans << endl;

    return 0;
}
