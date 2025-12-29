#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long k;
    cin >> k;

    long long midPoint;

    if(n % 2 == 0)
        midPoint = n / 2;
    else
        midPoint = (n / 2) +1;


    if(k <= midPoint)
        cout << ((k - 1) * 2) + 1;
    else
        cout << (k - midPoint) * 2;
    return 0;
}