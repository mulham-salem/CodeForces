#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x = n - 10;

    if (x == 10)
        cout << 15;
    else if ((x >= 2 && x <= 9) || x == 1 || x == 11)
        cout << 4;
    else
        cout << 0;

    return 0;
}
