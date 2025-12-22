#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    char w[100];

    while(n--)
    {
        cin >> w;

        if(strlen(w) > 10)
        {
            cout << w[0]
                 << strlen(w) - 2
                 << w[strlen(w) - 1]
                 << endl;
        }
        else
            cout << w << endl;
    }
    return 0;
}