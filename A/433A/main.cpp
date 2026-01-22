#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int c100 = 0, c200 = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 100)
            c100++;
        else
            c200++;
    }

    int total = (100 * c100) + (200 * c200);

    if ((total /= 100) % 2 != 0) {
        cout << "NO";
        return 0;
    }
    else {
        if (c200 % 2 == 0) {
            cout << "YES";
            return 0;
        }
        else {
            if (c100 >= 2) {
                cout << "YES";
                return 0;
            }
            else
                cout << "NO";
        }
    }

    return 0;
}
