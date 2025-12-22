#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for(int i=0; i<s.length(); i++)
        s[i] = towlower(s[i]);

    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='a' || s[i]=='o' || s[i]=='y' || s[i]=='e' || s[i]=='u' || s[i]=='i')
        {
            i++;
            if(s[i]=='a' || s[i]=='o' || s[i]=='y' || s[i]=='e' || s[i]=='u' || s[i]=='i')
               continue;

            else if(i != s.length())
               cout << "." << s[i];
        }
        else
            cout << "." << s[i];

    }
    return 0;
}