#include <bits/stdc++.h>
using namespace std;

int main() {

    string a;
    cin >> a;

    int freq[10] = {};

    for (char c : a) {
        freq[c - '0']++;
    }

    freq[1]--;
    freq[6]--;
    freq[8]--;
    freq[9]--;

    string prefix;

    int zeroCount = freq[0];

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j < freq[i]; j++) {
            prefix += char(i + '0');
        }
    }

    int remainder = 0;

    for (char c : prefix) {
        remainder = (remainder * 10 + (c - '0')) % 7;
    }

    string p = "1689";

    do {

        int value = stoi(p);

        if ((remainder * 10000 + value) % 7 == 0) {

            cout << prefix << p;

            for (int i = 0; i < zeroCount; i++) {
                cout << '0';
            }

            cout << '\n';

            return 0;
        }

    } while (next_permutation(p.begin(), p.end()));

    cout << 0 << '\n';

    return 0;
}
