#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    do {

        int digit = n % 10;

        if (digit >= 5) {
            cout << "-O|";
        }
        else {
            cout << "O-|";
        }

        int remaining = digit % 5;

        for (int i = 0; i < remaining; i++) {
            cout << "O";
        }

        cout << "-";

        for (int i = 0; i < 4 - remaining; i++) {
            cout << "O";
        }

        cout << endl;

        n /= 10;

    } while (n > 0);

    return 0;
}
