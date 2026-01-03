#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long x;
    cin >> x;

    long long d;
    char op;

    long long sumX;
    sumX = x;

    long long sumD;
    sumD = 0;

    for(int i=0; i<n; i++)
    {
        cin >> op >> d;

        if(op == '+')
            sumX += d;
        else
        {
            if(d > sumX)
            {
                d = 0;
                sumD++;
            }

            else
                sumX -= d;
        }

    }
    cout << sumX << " " << sumD;
    return 0;
}