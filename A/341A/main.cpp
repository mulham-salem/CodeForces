#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a.begin(), a.end());

    long long numerator = sum;

    for (int i = 0; i < n; i++) {
        numerator += 2LL * a[i] * (2LL * i - n + 1);
    }

    long long denominator = n;
    long long g = gcd(abs(numerator), denominator);

    cout << numerator / g << " " << denominator / g << '\n';

    return 0;
}
