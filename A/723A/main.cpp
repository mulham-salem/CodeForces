#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int x1, x2, x3;
    cin >> x1 >> x2 >> x3;

    int b[3] = {x1, x2, x3};

    sort(b, b+3);

    int c = 0;

    c += b[1]-b[0];
    c += b[2]-b[1];

    cout << c;

    return 0;
}