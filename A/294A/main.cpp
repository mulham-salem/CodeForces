#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int birds[n];
    for(int i=0; i<n; i++)
    {
        cin >> birds[i];
    }

    int m;
    cin >> m;

    int y, x;
    for(int i=0; i<m;  i++)
    {
        cin >> x >> y;
        x--;

        if(x != 0)
            birds[x-1] += y-1;

        if(x != n-1)
            birds[x+1] += birds[x]-y;

        birds[x] = 0;

    }
    cout << endl;
    for(int i=0; i<n; i++)
    {
        cout << birds[i] << endl;
    }

    return 0;
}