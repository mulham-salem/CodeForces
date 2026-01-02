#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    char a[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(i % 2 == 0)
                a[i][j] = '#';
            else
                a[i][j] = '.';
        }
    }
    int c = 0;
    for(int i=0; i<n; i++)
    {
        if(i % 2 != 0)
        {
            if(c%2==0)
               a[i][m-1] = '#';
            else
               a[i][0] = '#';
            c++;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cout << a[i][j];

        cout << endl;
    }
    return 0;
}