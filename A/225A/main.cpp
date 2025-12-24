#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x;
    cin >> x;

    int a;
    int b;
    for(int i=0; i<n; i++)
    {
        cin >> a >> b;

        if(a==x || a==7-x || b==x || b==7-x)
        {
            cout << "NO";
            return 0;
        }

    }
    cout << "YES";
    return 0;
}