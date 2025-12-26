#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int rows = 5;
    const int columns = 5;

    int array[rows][columns];
    int x = 0;

    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<columns; j++)
        {
            cin >> array[i][j];
            if(array[i][j] == 1)
            x = abs(i - 2) + abs(j - 2);
        }
    }
    cout << x << endl;

    return 0;
}
