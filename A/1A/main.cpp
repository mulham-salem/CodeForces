#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long m;
    cin >> m;

    long long a;
    cin >> a;

    long long x;
    x = n/a;

    long long y;
    y = m/a;

    if(n % a != 0)
        x++;
    if(m % a != 0)
        y++;

    cout << x*y;

    return 0;
}
