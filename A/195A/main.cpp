#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    long long ans = (a * c) / b - c;

    if ((a * c) % b != 0)
        ans++;

    cout << ans << endl;

    return 0;
}
