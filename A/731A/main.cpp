#include <iostream>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

int main()
{
    char s[100];
    cin >> s;
    int rotation = 0;
    int difference = 0;
    int flag = 97;
    for(int i=0; i<strlen(s); i++)
    {
        difference = abs(flag - s[i]);
        if(difference > 13)
        {
            difference = 26 - difference;
        }
        rotation += difference;
        flag = s[i];
    }
    cout << rotation << endl;
    return 0;
}