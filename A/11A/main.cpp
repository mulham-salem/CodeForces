#include <bits/stdc++.h>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long d;
    cin >> d;

    vector<long long> num(n);

    for (int i = 0; i < n; i++)
        cin >> num[i];

    int move_count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] >= num[i+1])
        {
            long long diff = num[i] - num[i+1];
            long long needed = diff / d + 1;
            num[i+1] += needed * d;
            move_count += needed;
        }
    }

    cout << move_count;

    return 0;
}
