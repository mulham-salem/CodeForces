#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int h[n], a[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<1; j++)
        {
            cin >> h[i] >> a[i];
        }
        cout << endl;
    }
    int counter = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(h[i] == a[j])
             counter++;
        }
        cout << endl;
    }

    cout << counter;
    return 0;
}