#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int p, q;
    int c1 = 0, c2 = 0;

    for(int i=0; i<n; i++)
    {
        cin >> p >> q;
        c1 = q - p;

        if(c1 != 0 && c1 >= 2)
            c2++;
        c1 = 0;
    }
    cout << c2;
    return 0;
}