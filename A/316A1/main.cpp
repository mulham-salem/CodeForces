#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int cnt[10] = {};
    bool used[10] = {};

    long long ans = 1;

    // Count distinct letters
    int letters = 0;

    for (char c : s) {
        if (c >= 'A' && c <= 'J') {
            if (!used[c - 'A']) {
                used[c - 'A'] = true;
                letters++;
            }
        }
    }

    // First character
    if (s[0] == '?') {
        ans *= 9;
    }
    else if (s[0] >= 'A' && s[0] <= 'J') {
        ans *= 9;
    }

    // Remaining characters
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == '?') {
            ans *= 10;
        }
    }

    // Assign digits to distinct letters.
    // The first letter appearing at position 0 cannot use 0.
    int firstLetter = -1;

    if (s[0] >= 'A' && s[0] <= 'J') {
        firstLetter = s[0] - 'A';
    }

    if (firstLetter != -1) {
        // First letter: 9 choices
        // Other distinct letters: 9, 8, 7, ... choices
        int choices = 9;

        for (int i = 1; i < letters; i++) {
            ans *= choices;
            choices--;
        }
    }
    else {
        // No letter starts the code.
        // All distinct letters can use 10, 9, 8, ... digits.
        int choices = 10;

        for (int i = 0; i < letters; i++) {
            ans *= choices;
            choices--;
        }
    }

    cout << ans << '\n';

    return 0;
}
