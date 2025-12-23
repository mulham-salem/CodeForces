#include <iostream>

using namespace std;

int main()
{
    int r1, r2;
    cin >> r1 >> r2;

    int c1, c2;
    cin >> c1 >> c2;

    int d1, d2;
    cin >> d1 >> d2;

    int a, b, c, d;

    for(int i=1; i<10; i++)
    {
        a = i;
        for(int j=1; j<10; j++)
        {
            b = j;
            for(int k=1; k<10; k++)
            {
                c = k;
                for(int l=1; l<10; l++)
                {
                    d = l;
                    if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
                    {
                        if(r1==a+b && r2==c+d && c1==a+c && c2==b+d && d1==a+d && d2==b+c)
                        {
                            cout << endl;
                            cout << a << " " << b << "\n" << c << " " << d;
                            return 0;
                        }

                    }

                }

            }

        }

    }
    cout << endl;
    cout << "-1";
    return 0;
}