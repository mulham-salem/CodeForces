#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    string s = "0123456789";
    string a;

    int count1 = 0;
    int countK = 0;

    int x = -1;

    while(n--)
    {
        cin >> a;
        for(int i=0; i<=k; i++)
        {
            x = a.find(s[i]);
            if(x != -1)
            {
                count1++;
                x = -1;
            }

        }
        if(count1 >= k+1)
            countK++;

        count1 = 0;
    }
    cout << endl;
    cout << countK;
    return 0;
}