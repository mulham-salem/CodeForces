#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;

    int p;
    cin >> p;

    int a[200];

    for(int i=0; i<p; i++)
        cin >> a[i];

    int q;
    cin >> q;

    for(int i=p; i<p+q; i++)
        cin >> a[i];

    int level = 0;

    for(int j=1; j<=n; j++)
    {
        level = 0;
        for(int i=0; i<p+q; i++)
        {
            if(j == a[i])
            {
                level = 1;
                break;
            }

        }

        if(level == 0)
        {
            cout << "Oh, my keyboard!";
            break;
        }

    }

    if(level)
        cout << "I become the guy.";

    return 0;
}