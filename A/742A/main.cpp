#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n == 0)
        cout << "1";

    else if(n > 0)
    {
        int units[4] = {8, 4, 2, 6};
        n = (n-1) % 4;
        cout << units[n];
    }

    return 0;
}