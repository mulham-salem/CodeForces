#include <bits/stdc++.h>
using namespace std;

int main() {

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    int dr = abs(r1 - r2);
    int dc = abs(c1 - c2);

    // Rook
    int rook = 2;

    if (r1 == r2 || c1 == c2)
        rook = 1;

    // Bishop
    int bishop = 0;

    if (dr == dc)
        bishop = 1;
    else if ((r1 + c1) % 2 == (r2 + c2) % 2)
        bishop = 2;

    // King
    int king = max(dr, dc);

    cout << rook << " " << bishop << " " << king << endl;

    return 0;
}
