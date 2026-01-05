#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string a;
    cin >> a;

    string b;
    cin >> b;

    int l1 = a.length();
    int l2 = b.length();

    if(a == b)
        cout << "-1";

    else if(l1 > l2)
        cout << l1;

    else
        cout << l2;
    return 0;
}