#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string a;
    cin >> a;

    string b;
    string c;

    int g1 = 1;
    int g2 = 0;

    for(int i=1; i<n; i++)
    {
        cin >> b;
        if(a == b)
            g1++;
        else
        {
            c = b;
            g2++;
        }

    }

    if(g1 > g2)
        cout << a;
    else
        cout << c;

    return 0;
}