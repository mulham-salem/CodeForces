#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;

    int totalDrink = k * l;
    int totalLimes = c * d;
    int totalSalt = p;

    int byDrink = totalDrink / (n * nl);
    int byLime  = totalLimes / n;
    int bySalt  = totalSalt / (n * np);

    int result = min({byDrink, byLime, bySalt});
    cout << result;

    return 0;
}
