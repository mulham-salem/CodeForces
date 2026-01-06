#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int l = s.size();

    int f1 = 0;
    int f2 = l%2;

    int count = l/2;

    for(int i=1; i<l; i++)
    {
        if(s[i] == '1')
        {
            f1 = 1;
            break;
        }
    }
    if(f1 && f2)
        count++;
    cout << count;

    return 0;
}