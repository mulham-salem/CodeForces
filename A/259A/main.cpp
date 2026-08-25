#include <bits/stdc++.h>
using namespace std;

int main() {
    for (int i = 0; i < 8; i++) {
        string row;
        cin >> row;

        for (int j = 0; j < 8; j++) {
            int next = (j + 1) % 8;

            if (row[j] == row[next]) {
                cout << "NO\n";
                return 0;
            }
        }
    }

    cout << "YES\n";

    return 0;
}
