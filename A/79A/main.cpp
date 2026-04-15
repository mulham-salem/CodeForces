#include <iostream>
using namespace std;

int main() {
    long long x, y;
    cin >> x >> y;

    bool cielTurn = true;

    while (true) {
        if (cielTurn) {
            // Ciel
            if (x >= 2 && y >= 2) {
                x -= 2; y -= 2;
            } else if (x >= 1 && y >= 12) {
                x -= 1; y -= 12;
            } else if (y >= 22) {
                y -= 22;
            } else {
                cout << "Hanako";
                break;
            }
        } else {
            // Hanako
            if (y >= 22) {
                y -= 22;
            } else if (x >= 1 && y >= 12) {
                x -= 1; y -= 12;
            } else if (x >= 2 && y >= 2) {
                x -= 2; y -= 2;
            } else {
                cout << "Ciel";
                break;
            }
        }

        cielTurn = !cielTurn;
    }

    return 0;
}
