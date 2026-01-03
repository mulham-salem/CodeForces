#include <iostream>

using namespace std;

int main()
{
    long long x;
    cin >> x;

    int count = 0;

    while(x != 0)
    {
        if(x % 2 != 0)
        {
            count++;
            x = x / 2;
        }
        else
            x = x / 2;

    }
    cout << count;
    return 0;
}