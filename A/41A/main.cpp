#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;

    string t;
    cin >> t;

    int count = 0;

    for(int i=(t.size()-1), j=0; i>=0; i--, j++)
    {
        if(t[i] == s[j])
            count++;
    }
    if(count == s.size())
        cout << "YES";
    else
        cout << "NO";
    return 0;
}