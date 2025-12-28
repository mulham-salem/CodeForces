#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;

    char a[n];
    cin >> a;

    int first = 0;
    int last = 0;

    for(int i=0; i<n; i++)
    {
        if(a[i] != '.')
        {
            first = i;
            break;
        }
    }

    for(int i=n-1; i>=0; i--)
    {
        if(a[i] != '.')
        {
            last = i;
            break;
        }
    }

    if(a[first] == 'R' && a[last] == 'R')
        cout << first+1 << " " << last+1+1;

    else if(a[first] == 'L' && a[last] == 'L')
        cout << last+1 << " " << first;

    else if(a[first] == 'R' && a[last] == 'L')
    {
        for(int i=0; i<n; i++)
        {
            if(a[i] == 'L')
            {
                last = i;
                break;
            }

        }
        cout << first+1 << " " << last;
    }
    return 0;
}