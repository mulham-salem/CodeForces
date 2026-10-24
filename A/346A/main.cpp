#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[100];
    int mx = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
    }

    int g = 0;

    for (int i = 0; i < n; i++) {
        g = __gcd(g, a[i]);
    }

    if ((mx / g - n) % 2 == 1) {
        cout << "Alice";
    } else {
        cout << "Bob";
    }

    return 0;
}
