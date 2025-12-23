#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[100];

    int sumTotal = 0;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        sumTotal += a[i];
    }

    sort(a, a+n);

    int get = 0;
    int coin = 0;

    for(int i=n-1; i>=0; i--)
    {
        get += a[i];
        coin++;
        sumTotal -= a[i];

        if(get > sumTotal)
        {
            cout << coin;
            break;
        }

    }
    return 0;
}