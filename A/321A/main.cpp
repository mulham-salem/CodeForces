#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    // Simulate one cycle
    long long dx = 0, dy = 0;
    for (char c : s) {
        if (c == 'U') dy++;
        else if (c == 'D') dy--;
        else if (c == 'L') dx--;
        else if (c == 'R') dx++;
    }

    // Check starting position (before any move)
    long long x = 0, y = 0;
    if (x == a && y == b) {
        cout << "Yes" << endl;
        return 0;
    }

    // Check each position after each move in one cycle
    for (char c : s) {
        if (c == 'U') y++;
        else if (c == 'D') y--;
        else if (c == 'L') x--;
        else if (c == 'R') x++;

        // We need: x + k*dx = a, y + k*dy = b for some k >= 0
        long long rx = a - x;
        long long ry = b - y;

        if (dx == 0 && dy == 0) {
            // No net movement per cycle
            if (rx == 0 && ry == 0) {
                cout << "Yes" << endl;
                return 0;
            }
        } else if (dx == 0) {
            // Only dy matters for k
            if (rx == 0 && ry % dy == 0 && ry / dy >= 0) {
                cout << "Yes" << endl;
                return 0;
            }
        } else if (dy == 0) {
            // Only dx matters for k
            if (ry == 0 && rx % dx == 0 && rx / dx >= 0) {
                cout << "Yes" << endl;
                return 0;
            }
        } else {
            // Both dx and dy nonzero
            if (rx % dx == 0 && ry % dy == 0 && rx / dx == ry / dy && rx / dx >= 0) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}
