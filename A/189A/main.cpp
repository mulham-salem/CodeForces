#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    int ans = 0;
    for (int i = 0; i <= n / a; i++)
    {
        for (int j = 0; j <= n / b; j++)
        {
            int rest = n - i*a - j*b;
            if (rest < 0) continue;

            if (rest % c == 0)
            {
                int k = rest / c;
                ans = max(ans, i + j + k);
            }
        }
    }
    cout << ans;

    return 0;
}
