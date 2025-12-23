#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int p;
    int array[100];

    for(int i=1; i<=n; i++)
    {
        cin >> p;
        array[p] = i;
    }
    for(int i=1; i<=n; i++)
        cout << array[i] << " ";
    return 0;
}