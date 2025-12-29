#include <iostream>

using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    string s;
    cin >> s;

    int l = s.size();

    for(int i=0; i<l; i++)
    {
        for(int j=0; j<l-1; j++)
        {
            if(s[j] > s[j+1])
            swap(s[j], s[j+1]);
        }

    }

    for(int i=0; i<l; i++)
    {
        if(s[i] != '+')
        {
            cout << s[i];
            if(s[i] <= s[i+1])
            {
                cout << "+";
            }

        }

    }
    return 0;
}