#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    int x[n];
    for(int i=0; i<n; i++)
        cin >> x[i];

    int ans = 1e9;
    for(int i=0; i<n-1; i++)
    {
        if(s[i] == 'R' && s[i+1] == 'L')
        {
            ans = min(ans, (x[i+1]-x[i])/2);
        }

    }

    if(ans == 1e9)
        cout << -1;
    else
        cout << ans;
    return 0;
}