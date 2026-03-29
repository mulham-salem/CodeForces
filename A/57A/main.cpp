#include <iostream>
#include <cmath>
using namespace std;

int getPos(int n, int x, int y) {
    if (y == 0) return x;                 // bottom
    if (x == n) return n + y;             // right
    if (y == n) return 3 * n - x;         // top
    return 4 * n - y;                     // left
}

int main() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int p1 = getPos(n, x1, y1);
    int p2 = getPos(n, x2, y2);

    int d = abs(p1 - p2);
    int perimeter = 4 * n;

    cout << min(d, perimeter - d) << endl;

    return 0;
}
