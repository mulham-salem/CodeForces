#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    string result = to_string(a);
    int mod = a % b;

    while (n--) {
        bool found = false;

        for (int digit = 0; digit <= 9; digit++) {
            int new_mod = (mod * 10 + digit) % b;
            if (new_mod == 0) {
                result.push_back('0' + digit);
                mod = new_mod;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << -1;
            return 0;
        }
    }

    cout << result;
    return 0;
}
