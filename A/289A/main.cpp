#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int k;
    cin >> k;

    int l, r;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        cin >> l >> r;
        sum += (r - l) + 1;
    }
    sum = (k - (sum%k)) % k;
    cout << sum;
    return 0;
}