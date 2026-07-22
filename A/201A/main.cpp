#include <iostream>
using namespace std;

int main() {
    int x;
    cin >> x;

    if (x == 3) {
        cout << 5;
        return 0;
    }

    for (int n = 1; ; n += 2) {
        int k = n / 2;
        int mx = k * k + (k + 1) * (k + 1);

        if (mx >= x) {
            cout << n;
            break;
        }
    }

    return 0;
}
