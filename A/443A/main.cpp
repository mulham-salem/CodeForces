#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char l[1000];
    gets(l);

    int s = strlen(l);
    int counter = 0;

    sort(l, l+s);
    for(int i=0; i<s; i++)
    {
        if(l[i] >= 97 && l[i] <= 122)
        {
            if(l[i] != l[i+1])
                counter++;
        }

    }
    cout << counter;
    return 0;
}