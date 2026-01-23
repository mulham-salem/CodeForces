#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;

    if (s.length() != t.length()) {
        cout << "NO";
        return 0;
    }

    int diff = 0;
    int index[2];
    int k = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != t[i]) {
            if (k < 2)
                index[k++] = i;
            diff++;
        }
    }

    if (diff != 2) {
        cout << "NO";
        return 0;
    }
    else {
        if (s[index[0]] == t[index[1]] &&
            s[index[1]] == t[index[0]]) {
            cout << "YES";
        }
        else {
            cout << "NO";
        }
    }

    return 0;
}
