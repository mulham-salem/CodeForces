#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int answer = 4;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;

            if (x == 1)
            {
                if (i == 1 || i == n || j == 1 || j == m)
                {
                    answer = 2;
                }
            }
        }
    }

    cout << answer << endl;

    return 0;
}
