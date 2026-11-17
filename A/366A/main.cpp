#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    for (int i = 1; i <= 4; i++) {

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int firstMin = min(a, b);
        int secondMin = min(c, d);

        if (firstMin + secondMin <= n) {

            int firstGift = firstMin;
            int secondGift = n - firstGift;

            cout << i << " " << firstGift << " " << secondGift;

            return 0;
        }
    }

    cout << -1;

    return 0;
}
