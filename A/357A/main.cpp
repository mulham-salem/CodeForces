#include <iostream>
using namespace std;

int main() {
    int m;
    cin >> m;

    int c[100];

    int beginner = 0;
    int intermediate = 0;

    for (int i = 0; i < m; i++) {
        cin >> c[i];
        intermediate += c[i];
    }

    int x, y;
    cin >> x >> y;

    for (int k = 1; k < m; k++) {

        beginner += c[k - 1];
        intermediate -= c[k - 1];

        if (beginner >= x && beginner <= y &&
            intermediate >= x && intermediate <= y) {

            cout << k + 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}
