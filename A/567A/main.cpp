#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    for(int i=0; i<n; i++)
    {
        long long mini;
        long long maxi;

        if(i == 0)
        {
            mini = abs(arr[i] - arr[i+1]);
            maxi = abs(arr[i] - arr[n-1]);
        }

        else if(i == n-1)
        {
            mini = abs(arr[i] - arr[i-1]);
            maxi = abs(arr[i] - arr[0]);
        }

        else
        {
            mini = min(abs(arr[i]-arr[i-1]),
                       abs(arr[i]-arr[i+1]));

            maxi = max(abs(arr[i]-arr[0]),
                       abs(arr[i]-arr[n-1]));
        }

        cout << mini << " " << maxi << endl;
    }
    return 0;
}