#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


long long dist2(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool isRight(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long d12 = dist2(x1, y1, x2, y2);
    long long d23 = dist2(x2, y2, x3, y3);
    long long d31 = dist2(x3, y3, x1, y1);

    long long sides[3] = {d12, d23, d31};
    sort(sides, sides + 3);

    return (sides[0] > 0) && (sides[0] + sides[1] == sides[2]);
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (isRight(x1, y1, x2, y2, x3, y3)) {
        cout << "RIGHT" << endl;
        return 0;
    }

    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};

    int points[3][2] = {{x1, y1}, {x2, y2}, {x3, y3}};

    for (int i = 0; i < 3; i++) {
        for (int d = 0; d < 4; d++) {

            int originalX = points[i][0];
            int originalY = points[i][1];

            points[i][0] += dx[d];
            points[i][1] += dy[d];

            if (isRight(points[0][0], points[0][1],
                        points[1][0], points[1][1],
                        points[2][0], points[2][1])) {
                cout << "ALMOST" << endl;
                return 0;
            }

            points[i][0] = originalX;
            points[i][1] = originalY;
        }
    }

    cout << "NEITHER" << endl;

    return 0;
}
