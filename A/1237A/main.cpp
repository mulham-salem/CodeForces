#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    int b[n];

    bool x = true;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];

        if(a[i] % 2 == 0)
            b[i] = a[i] / 2;
        else
        {
            if(x)
                b[i] = ceil(a[i] / 2.0);
            else
                b[i] = floor(a[i] / 2.0);

            x = !x;
        }

    }
    cout << endl;

    for(int i=0; i<n; i++)
        cout << b[i] << endl;

    return 0;
}