#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int hours = a;
    int c = a;

    while (c >= b)
    {
        c -= b;
        hours++;
        c++;
    }

    cout << hours << endl;

    return 0;
}
