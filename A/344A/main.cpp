#include <iostream>

using namespace std;

int main()
{
    int magnets;
    cin >> magnets;
    int n[magnets];
    int groups = 0;
    int i=0;
    while(i < magnets)
    {
       cin >> n[i];
       i++;
    }
    for(int i=0; i<magnets; i++)
    {
        if(n[i] != n[i+1])
			groups++;
    }
    cout << endl;
    cout << groups << endl;

    return 0;
}
