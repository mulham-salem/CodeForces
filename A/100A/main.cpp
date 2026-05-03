#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, n1;
    cin >> n >> k >> n1;

    int need = ( (n + n1 - 1) / n1 ) * ( (n + n1 - 1) / n1 );

    if (k >= need)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
