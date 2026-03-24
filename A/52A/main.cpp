#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a;

    int c1 = 0, c2 = 0, c3 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) c1++;
        else if (a == 2) c2++;
        else c3++;
    }

    int rep_count = n - max({c1, c2, c3});

    cout << rep_count;
    return 0;
}
