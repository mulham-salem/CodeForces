#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int e;
    int sum = 0;
    int counter = 0;
    for(int i=0; i<n; i++)
    {
        cin >> e;

        if(e >= 0) 
            sum += e;
        else 
        {
            if(sum == 0)
                counter++;
            else
                sum--;
        }
    }

    cout << counter << endl;
    return 0;
}

