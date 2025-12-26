#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x;
    cin >> x;

    int mn = x, mx = x;
    int amazing = 0;

    for (int i = 1; i < n; i++)
    {
        cin >> x;

        if (x > mx) {
            amazing++;
            mx = x;
        } else if (x < mn) {
            amazing++;
            mn = x;
        }
    }

    cout << amazing;


    return 0;
}
