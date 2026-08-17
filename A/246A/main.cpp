#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << -1 << '\n';
        return 0;
    }

    cout << 2 << ' ' << 2;

    for (int i = 2; i < n; i++) {
        cout << ' ' << 1;
    }

    cout << '\n';

    return 0;
}
