#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int d[7];
    for (int i = 0; i < 7; i++)
        cin >> d[i];

    while (true) {
        for (int i = 0; i < 7; i++) {
            n -= d[i];
            if ( n <= 0 ) {
                cout << i + 1;
                return 0;
            }
        }
    }

    return 0;
}
