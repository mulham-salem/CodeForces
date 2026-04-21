#include <iostream>
#include <numeric>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long g = gcd(a, b);
    long long l = (a / g) * b;

    long long dasha = l / a;
    long long masha = l / b;

    // remove the one tie
    dasha--;
    masha--;

    // give tie to slower train
    if (a > b) dasha++;
    else masha++;

    if (dasha > masha) cout << "Dasha";
    else if (masha > dasha) cout << "Masha";
    else cout << "Equal";

    return 0;
}
