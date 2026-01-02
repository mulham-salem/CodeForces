#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    char s[n];

    for(int i=0; i<n; i++)
    {
        cin >> s[i];
        s[i] = tolower(s[i]);
    }

    sort(s, s+n);

    int counter = 0;

    for(int i=0; i<n; i++)
    {
        if(s[i] != s[i+1])
           counter++;
    }

    if(counter == 26)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}