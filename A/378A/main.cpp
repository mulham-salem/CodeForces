#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int first = 0, draw = 0, second = 0;

    for (int i = 1; i <= 6; i++) {
        int d1 = abs(a - i);
        int d2 = abs(b - i);

        if (d1 < d2)
            first++;
        else if (d1 == d2)
            draw++;
        else
            second++;
    }

    cout << first << " " << draw << " " << second << endl;

    return 0;
}
