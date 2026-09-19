#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    int g = 0;

    for (int &x : a) {
        cin >> x;
        g = __gcd(g, x);
    }

    for (int x : a) {
        if (x == g) {
            cout << g << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
