#include <iostream>

using namespace std;

char a[4][4];

bool test2(int i, int j)
{
    if(i+1 == 4 || j+1 == 4)
        return false;

        return a[i][j] == a[i][j+1] && a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1];
}

bool test1()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(test2(i, j))
                return true;
        }

    }
    return false;
}

int main()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cin >> a[i][j];
    }

    bool x = test1();

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            char now = a[i][j];

            if(a[i][j] == '.')
                a[i][j] = '#';
            else
                a[i][j] = '.';

            if(test1())
                x = true;

            a[i][j] = now;

        }

    }

    if(x)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}