#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    double b;
    cin >> n >> b;

    vector<double> a(n);
    double sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    double total = sum + b;
    double x = total / n;

    // check feasibility
    for (int i = 0; i < n; i++) {
        if (x < a[i]) {
            cout << -1 << "\n";
            return 0;
        }
    }

    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++) {
        cout << (x - a[i]) << "\n";
    }

    return 0;
}
