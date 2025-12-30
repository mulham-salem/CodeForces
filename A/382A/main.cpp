#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s1[28];
    gets(s1);

    char s2[27];
    gets(s2);

    int lS1 = strlen(s1);
    int lS2 = strlen(s2);

    int t;
    for(int i=0; i<lS1; i++)
    {
        if(s1[i] == '|')
        {
            t = i;
            break;
        }

    }

    int l1 = t;
    int l2 = lS1 - t - 1;

    int n;
    int m;

    if(l1 == l2)
    {
        if(lS2 & 1)
            cout << "Impossible";

        else
        {
            for(int i=0; i<lS2/2; i++)
                cout << s2[i];

            for(int i=0; i<l1; i++)
                cout << s1[i];

            cout << '|';

            for(int i=t+1; i<lS1; i++)
                cout << s1[i];

            for(int i=lS2/2; i<lS2; i++)
                cout << s2[i];
        }

    }

    else
    {
        if(l1 > l2)
        {
            n = l1 - l2;
            m = lS2 - n;

            if(m & 1 || m < 0)
                cout << "Impossible";

            else
            {

                for(int i=n+m/2; i<lS2; i++)
                    cout << s2[i];

                for(int i=0; i<l1; i++)
                    cout << s1[i];

                cout << '|';

                for(int i=t+1; i<lS1; i++)
                    cout << s1[i];

                for(int i=0; i<n+m/2; i++)
                    cout << s2[i];
            }

        }
        else
        {
            n = l2 - l1;
            m = lS2 - n;

            if(m & 1 || m < 0)
                cout << "Impossible";
            else
            {
                for(int i=0; i<n+m/2; i++)
                    cout << s2[i];

                for(int i=0; i<l1; i++)
                    cout << s1[i];

                cout << '|';

                for(int i=t+1; i<lS1; i++)
                    cout << s1[i];

                for(int i=n+m/2; i<lS2; i++)
                    cout << s2[i];

            }

        }

    }
	return 0;
}