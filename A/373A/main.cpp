#include <bits/stdc++.h>
using namespace std;

int main() {

    int k;
    cin >> k;

    int freq[10] = {0};

    for (int i = 0; i < 4; i++) {

        string s;
        cin >> s;

        for (int j = 0; j < 4; j++) {

            if (s[j] != '.') {

                freq[s[j] - '0']++;

            }
        }
    }

    int capacity = 2 * k;

    for (int i = 1; i <= 9; i++) {

        if (freq[i] > capacity) {

            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}
