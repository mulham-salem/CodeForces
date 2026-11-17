#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, d;
    cin >> n >> d;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    sort(a.begin(), a.end());

    int profit = 0;

    for (int i = 0; i < m; i++) {

        if (i < n) {
            profit += a[i];
        }
        else {
            profit -= d;
        }
    }

    cout << profit << endl;

    return 0;
}
