#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    // If all elements are 1
    if (a[n - 1] == 1) {
        a[n - 1] = 2;
    }
    else {
        // Replace the largest element with 1
        a[n - 1] = 1;
    }

    sort(a.begin(), a.end());

    for (int x : a)
        cout << x << ' ';

    return 0;
}
