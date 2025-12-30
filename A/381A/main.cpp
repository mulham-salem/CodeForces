#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a[n];
    for(int i=0; i<n; i++)
    {
      cin >> a[i];
    }

    int i = 0;
    int j = n - 1;
    int max;
    int counter = 0;
    int player1 = 0;
    int player2 = 0;
    while(i <= j)
    {
        if(a[i] >= a[j])
        {
            max = a[i];
            i++;
        }
        else
        {
            max = a[j];
            j--;
        }

        if(counter % 2 == 0)
            player1 += max;
        else
            player2 += max;
        counter++;
    }
    cout << player1 << " " << player2 << endl;

    return 0;
}
