#include <iostream>
using namespace std;

int main() {
    long long xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya;
    cin >> xb >> yb;
    cin >> xc >> yc;

    long long abx = xb - xa;
    long long aby = yb - ya;

    long long bcx = xc - xb;
    long long bcy = yc - yb;

    long long cross = abx * bcy - aby * bcx;

    if (cross > 0)
        cout << "LEFT";
    else if (cross < 0)
        cout << "RIGHT";
    else
        cout << "TOWARDS";

    return 0;
}
