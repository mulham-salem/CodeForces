#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;

    while (t--) {

        char board[8][8];

        int r1 = -1, c1 = -1;
        int r2 = -1, c2 = -1;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {

                cin >> board[i][j];

                if (board[i][j] == 'K') {

                    if (r1 == -1) {
                        r1 = i;
                        c1 = j;
                    }
                    else {
                        r2 = i;
                        c2 = j;
                    }
                }
            }
        }

        if (abs(r1 - r2) % 4 == 0 &&
            abs(c1 - c2) % 4 == 0) {

            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
