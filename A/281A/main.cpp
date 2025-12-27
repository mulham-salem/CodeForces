#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[1001];
    cin >> s;

    for(int i=0; i<strlen(s); i++)
    {
        if(islower(s[0]))
            s[i] = towupper(s[i]);
    }
    cout << s;
    return 0;
}