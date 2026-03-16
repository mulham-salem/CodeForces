#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, V;
    cin >> n >> V;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    double x_max = 1e9;
    for(int i = 0; i < n; i++) {
        x_max = min(x_max, double(b[i]) / a[i]);
    }

    double total = 0;
    for(int i = 0; i < n; i++) total += a[i];
    double answer = min(double(V), total * x_max);

    cout << fixed << setprecision(10) << answer << endl;
    return 0;
}
