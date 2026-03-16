#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int distSq = x*x + y*y;

    int r = sqrt(distSq);
    if (r*r == distSq) {
        cout << "black" << endl;
        return 0;
    }

    if (x * y > 0) {
        cout << (r % 2 == 0 ? "black" : "white") << endl;
    }
    else if (x * y < 0) {
        cout << (r % 2 == 0 ? "white" : "black") << endl;
    }
    else {
        cout << "black" << endl;
    }

    return 0;
}
