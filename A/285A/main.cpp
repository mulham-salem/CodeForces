#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);

    for (int i = 0; i < n; i++)
        p[i] = i + 1;

    reverse(p.end() - k - 1, p.end());

    for (int x : p)
        cout << x << " ";

    return 0;
}
