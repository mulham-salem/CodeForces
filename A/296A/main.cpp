#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
        cin >> a[i];

    bool valid = true;

    for(int i=0; i<n; i++)
    {
        int c = 0;
        for(int j=0; j<n; j++)
        {
            if(a[i] == a[j])
                c++;

        }
        if(n < (2*c) - 1)
        {
            valid = false;
            break;
        }

    }
    if(valid)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}