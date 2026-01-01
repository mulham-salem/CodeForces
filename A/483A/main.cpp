#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long l;
    cin >> l;

    long long r;
    cin >> r;

    if(l % 2 != 0)
        l++;

    if(abs(l-r) < 2)
       cout << "-1";

    else
       cout << l << " " << (l+1)
                 << " " << (l+2);


    return 0;
}