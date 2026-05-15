#include <iostream>
using namespace std;

int main() {
    long long k, l;
    cin >> k >> l;

    int cnt = 0;

    while (l % k == 0) {
        l /= k;
        cnt++;
    }

    if (l == 1) {
        cout << "YES\n";
        cout << cnt - 1 << '\n';
    } else {
        cout << "NO\n";
    }

    return 0;
}
