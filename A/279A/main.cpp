#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    if (x == 0 && y == 0) {
        cout << 0;
        return 0;
    }

    int currentX = 0;
    int currentY = 0;

    // 0 = Right
    // 1 = Up
    // 2 = Left
    // 3 = Down
    int direction = 0;

    int turns = 0;
    int length = 1;

    bool firstSegment = true;

    while (true) {

        // Each length is used for two segments
        for (int repeat = 0; repeat < 2; repeat++) {

            // Every segment after the first requires one turn
            if (!firstSegment) {
                turns++;
            }

            firstSegment = false;

            for (int step = 0; step < length; step++) {

                if (direction == 0) {
                    currentX++;          // Right
                }
                else if (direction == 1) {
                    currentY++;          // Up
                }
                else if (direction == 2) {
                    currentX--;          // Left
                }
                else {
                    currentY--;          // Down
                }

                if (currentX == x && currentY == y) {
                    cout << turns;
                    return 0;
                }
            }

            direction = (direction + 1) % 4;
        }

        length++;
    }

    return 0;
}
