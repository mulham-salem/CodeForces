#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    char s[200];
    gets(s);    

    int flag = 1;
                
    for(int i=0; i<strlen(s); i++)
    {
        if(s[i]=='W' && s[i+1]=='U' && s[i+2]=='B')
        {
            i += 2;

            if(!flag)
                cout << " ";

            continue;
        }
        else
        {
            flag = 0;
            cout << s[i];
        }

    }
    return 0;
}