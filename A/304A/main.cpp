#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int triangle = 0;

    for (int a = 1; a <= n; a++)
    {
        for (int b = a; b <= n; b++)
        {
            int x = a*a + b*b;
            int c = (int)sqrt(x);
            if (c * c == x && c <= n)
                triangle++;
        }
    }

    cout << triangle;
    return 0;
}
