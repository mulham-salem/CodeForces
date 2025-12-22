#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int m;
    cin >> m;

    int c = 0;

    for(int i=1; i<=m; i++)
    {
        if(m % i == 0)
            c++;
    }

    if(c == 2)
    {
        c = 0;
        for(int i=n+1; i<=50; i++)
        {
            for(int j=1; j<=50; j++)
            {
                if(i % j == 0)
                    c++;
            }
            if(c == 2)
            {
                if(i == m)
                {
                    cout << "YES";
                    return 0;
                }
                else
                {
                    cout << "NO";
                    return 0;
                }

            }
            else
                c = 0;

        }

    }
    else
        cout << "NO";

    return 0;
}