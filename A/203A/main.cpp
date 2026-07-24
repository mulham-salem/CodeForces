#include <iostream>
using namespace std;

int main() {
    int x, t, a, b, da, db;
    cin >> x >> t >> a >> b >> da >> db;

    if (x == 0) {
        cout << "YES";
        return 0;
    }

    for (int i = 0; i < t; i++) {
        int first = a - i * da;
        if (first == x) {
            cout << "YES";
            return 0;
        }
    }

    for (int i = 0; i < t; i++) {
        int second = b - i * db;
        if (second == x) {
            cout << "YES";
            return 0;
        }
    }

    for (int i = 0; i < t; i++) {
        int first = a - i * da;

        for (int j = 0; j < t; j++) {
            int second = b - j * db;

            if (first + second == x) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";

    return 0;
}
