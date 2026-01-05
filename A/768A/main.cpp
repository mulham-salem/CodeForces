#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    sort(a, a+n);

    int number = 0;
    for(int i=0; i<n; i++)
    {
        if(i>0 && i<n-1)
        {
            if(a[i]>a[0] && a[i]<a[n-1])
                number++;
        }

    }
    cout << number;

    return 0;
}