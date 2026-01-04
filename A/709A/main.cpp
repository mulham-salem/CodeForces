#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;

    long long b;
    cin >> b;

    long long d;
    cin >> d;

    long long sum = 0;
    long long empty = 0;

    int a;

    for(int i=0; i<n; i++)
    {
        cin >> a;

        if(a <= b)
        sum += a;

        if(sum > d)
        {
           empty++;
           sum = 0;
        }
    }

    cout << empty;

    return 0;
}