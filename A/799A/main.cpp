#include <iostream>

using namespace std;

int main()
{
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int t1;

    if(n%k == 0)
        t1 = (n/k) * t;
    else
    {
        t1 = n/k;
        t1++;
        t1 *= t;
    }

    int t2;

    t2 = d + t;


    if(t1 <= t2)
        cout << "NO";
    else
        cout << "YES";



    return 0;
}