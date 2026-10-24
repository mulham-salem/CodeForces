#include <iostream>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long ans = 0;

    while (b != 0) {
        ans += a / b;

        long long temp = a % b;
        a = b;
        b = temp;
    }

    cout << ans << endl;

    return 0;
}
