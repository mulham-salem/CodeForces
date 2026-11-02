#include <iostream>
using namespace std;

int main() {
    int k, d;
    cin >> k >> d;

    if (d == 0) {
        if (k == 1) {
            cout << 0;
        }
        else {
            cout << "No solution";
        }
    }
    else {
        if (k == 1) {
            cout << d;
        }
        else {
            cout << 1;

            for (int i = 0; i < k - 2; i++) {
                cout << 0;
            }

            cout << d - 1;
        }
    }

    return 0;
}
