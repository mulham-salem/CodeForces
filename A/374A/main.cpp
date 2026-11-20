#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, m, i, j, a, b;
    cin >> n >> m >> i >> j >> a >> b;

    int ans = INT_MAX;

    int vertical[] = {
        i - 1,
        i - 1,
        n - i,
        n - i
    };

    int horizontal[] = {
        j - 1,
        m - j,
        j - 1,
        m - j
    };

    bool rowCanMove = (i - a >= 1 || i + a <= n);
    bool colCanMove = (j - b >= 1 || j + b <= m);

    for (int k = 0; k < 4; k++) {

        if (vertical[k] % a == 0 &&
            horizontal[k] % b == 0) {

            int x = vertical[k] / a;
            int y = horizontal[k] / b;

            if (x % 2 == y % 2) {

                int moves = max(x, y);

                if (moves > 0) {

                    if (x == 0 && !rowCanMove)
                        continue;

                    if (y == 0 && !colCanMove)
                        continue;
                }

                ans = min(ans, moves);
            }
        }
    }

    if (ans == INT_MAX) {
        cout << "Poor Inna and pony!" << endl;
    }
    else {
        cout << ans << endl;
    }

    return 0;
}
