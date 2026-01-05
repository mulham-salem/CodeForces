#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    string s = {"abcdefghijklmnopqrstuvwxyz"};
    string newPassword = "" ;

    for(int i=0; i<n; i++)
        newPassword += s[i%k];

    cout << newPassword;
    return 0;
}