#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int upp = 0;
    int low = 0;
    int l = s.length();
    for(int i=0; i<l; i++)
    {
        if(isupper(s[i]))
            upp++;

        else
            low++;
    }
    if(upp == low)
    {
       for(int i=0; i<l; i++)
       {
           s[i] = tolower(s[i]);
       }
       cout << s << endl;
    }

    else if(upp < low)
    {
        for(int i=0; i<l; i++)
        {
           s[i] = tolower(s[i]);
        }
        cout << s << endl;
    }

    else if(upp > low)
    {
        for(int i=0; i<l; i++)
        {
           s[i] = toupper(s[i]);
        }
        cout << s << endl;
    }

return 0;
}
