#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    int a[100];
    int count = 0;

    for(int i=1; i<=n; i++)
        cin >> a[i];

    for(int i=1; i<=n; i++)
    {
        if(a[i] > 0)
        {
            if(a[i] >= a[k])
                count++;
        }
    }
    cout << count;
    return 0;
}