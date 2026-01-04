#include <iostream>

using namespace std;

int main()
{

    int const nMax = 100;
    int const mMax = 100;

    char a[nMax][mMax];

    int n, m;
    cin >> n >> m;

    int count1 = 0;
    int count2 = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];

            if(a[i][j]=='W' || a[i][j]=='B' || a[i][j]=='G')
                count1++;
            else
                count2++;

        }

    }

    if(count1 > count2 && count2 == 0)
        cout << "#Black&White";

    else
        cout << "#Color";

    return 0;
}