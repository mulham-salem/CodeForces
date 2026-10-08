#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int minX = 31400, minY = 31400;
    int maxX = 0, maxY = 0;
    int totalArea = 0;

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        minX = min(minX, x1);
        minY = min(minY, y1);
        maxX = max(maxX, x2);
        maxY = max(maxY, y2);

        totalArea += (x2 - x1) * (y2 - y1);
    }

    int width = maxX - minX;
    int height = maxY - minY;

    if (width != height || totalArea != width * height)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}
