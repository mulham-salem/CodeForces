#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string t;
    cin >> t;

    int pos = 1;
    int j = 0;
    for(int i=0; i<t.size(); i++)
    {
        if(s[j] == t[i])
        {
            pos++;

               j++;
        }

    }

    cout << pos;
    return 0;
}