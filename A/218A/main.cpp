#include <iostream>

using namespace std;


int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    int arr[201];
    int nodes = (n * 2) + 1;

    for(int i=0; i<nodes; i++)
        cin >> arr[i];

    for(int i=0; i<nodes; i++)
    {
        if(i%2==1 && k && (arr[i]-1)>arr[i-1] && (arr[i]-1)>arr[i+1])
        {
            arr[i]--;
            k--;
        }

    }
    cout << endl;

    for(int i=0; i<nodes; i++)
        cout << arr[i] << " ";

    return 0;
}