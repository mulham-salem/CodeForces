#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    char str[305][305];
    char ch;
    char d;

    bool x;
    bool y;
    bool z;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cin >> str[i][j];
    }


    x = true;

    ch = str[0][0];

    for(int i=1; i<n; i++)
    {
        if(str[i][i] != ch)
        {
            x = false;
            break;
        }

    }


    y = true;

    int j = n - 1;

    for(int i=0; i<n; i++)
    {
        if(str[i][j--] != ch)
        {
            y = false;
            break;
        }

    }


    z = true;

    d = str[0][1];

    for(int i=0; i<n; i++)
    {
        if(z == false)
            break;
        for(int j=0; j<n; j++)
        {
            if(i == j || i+j == n-1)
                continue;
            else
            {
                if(!(str[i][j]==d && str[i][j]!=ch))
                {
                    z = false;
                    break;
                }

            }


        }


    }
        cout << endl;

        if(x && y && z)
            cout << "YES";
        else
            cout <<"NO";

    return 0;
}