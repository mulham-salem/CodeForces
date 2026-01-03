#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long m;
    cin >> m;

    long long count = 0;

    for(long long i=1; i<=n; i++)
        count += (m+(i%5))/5;

    cout << count;
    return 0;
}