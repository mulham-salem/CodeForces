#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int topSum = 0;
    int bottomSum = 0;
    bool canSwap = false;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        topSum += x;
        bottomSum += y;

        if ((x + y) % 2 != 0) {
            canSwap = true;
        }
    }

    if (topSum % 2 == 0 && bottomSum % 2 == 0) {
        cout << 0 << endl;
    }
    else if (topSum % 2 != 0 && bottomSum % 2 != 0 && canSwap) {
        cout << 1 << endl;
    }
    else {
        cout << -1 << endl;
    }

    return 0;
}
