#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;

    int max1 = -1;
    int max2 = -1;
    int winner = 0;

    for (int i = 0; i < n; i++) {

        int p;
        cin >> p;

        if (p > max1) {

            max2 = max1;
            max1 = p;
            winner = i + 1;

        }
        else if (p > max2) {

            max2 = p;

        }
    }

    cout << winner << " " << max2 << endl;

    return 0;
}
