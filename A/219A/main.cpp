#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;

    string s;
    cin >> s;

    map<char, int> freq;
    for (char c : s) {
        freq[c]++;
    }

    for (auto it : freq) {
        if (it.second % k != 0) {
            cout << -1;
            return 0;
        }
    }

    string k_string = "";
    for (auto it : freq) {
        k_string += string(it.second / k, it.first);
    }

    for (int i = 0; i < k; i++) {
        cout << k_string;
    }

    return 0;
}
