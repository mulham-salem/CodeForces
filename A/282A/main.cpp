#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x = 0;

    string s;

    while(n--)
    {
        cin >> s;

        if(s=="X++" || s=="++X")
            x++;

        if(s=="X--" || s=="--X")
            x--;

    }
    cout << x;
    return 0;
}