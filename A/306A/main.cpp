#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int base = n / m;
    int remainder = n % m;

    for (int i = 0; i < m; i++) {
        if (remainder > 0) {
            cout << base + 1 << " ";
            remainder--;
        } else {
            cout << base << " ";
        }
    }

    return 0;
}
