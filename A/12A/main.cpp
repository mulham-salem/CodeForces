#include <bits/stdc++.h>

using namespace std;

int main()
{
    char m[3][3];

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> m[i][j];

    bool ok = true;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (m[i][j] != m[2 - i][2 - j])
                ok = false;

    cout << (ok ? "YES" : "NO");

    return 0;
}
