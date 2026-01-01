#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    int a1, a2, a3, a4;
    cin >> a1 >> a2 >> a3 >> a4;

    char square[100000];
    cin >> square;
    int res = 0;
    for(int i=0; i<strlen(square); i++)
    { 
         if(square[i] == '1')
         res+=a1;

         else if(square[i] == '2')
         res+=a2;

         else if(square[i] == '3')
         res+=a3;

         else if(square[i] == '4')
         res+=a4;
    }
    cout << res << endl;
    return 0;
}
