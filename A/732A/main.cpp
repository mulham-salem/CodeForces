#include <iostream>

using namespace std;

int main()
{
    int k, r;
    cin >> k >> r;

    int sum = 1;
    int i = 0;
    bool b = true;

    while(b)
    {
        i++;
        sum = i * k;
        if((sum%10==0 || sum%10==r))
            b = false;
    }
    cout << i;
    return 0;
}