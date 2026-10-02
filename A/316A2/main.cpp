#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool used[10] = {};
    int letters = 0;
    int questions = 0;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (c >= 'A' && c <= 'J') {
            if (!used[c - 'A']) {
                used[c - 'A'] = true;
                letters++;
            }
        }

        if (i > 0 && c == '?') {
            questions++;
        }
    }

    long long ans = 1;

    bool startsWithLetter = s[0] >= 'A' && s[0] <= 'J';

    if (s[0] == '?') {
        ans = 9;
    }

    int choices;

    if (startsWithLetter) {
        ans = 9;
        choices = 9;

        for (int i = 1; i < letters; i++) {
            ans *= choices;
            choices--;
        }
    }
    else {
        choices = 10;

        for (int i = 0; i < letters; i++) {
            ans *= choices;
            choices--;
        }
    }

    cout << ans;

    for (int i = 0; i < questions; i++) {
        cout << '0';
    }

    cout << '\n';

    return 0;
}
