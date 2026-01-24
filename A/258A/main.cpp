#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int size = s.length();
    bool flag = false;

    for (int i = 0; i < size-1; i++) {
        if (s[i] == '1' && s[i+1] == '0' && !flag) {
            s.erase(i+1, 1);
            flag = true;
            break;
        }
    }

    if (!flag)
        s.erase(size-1, 1);

    cout << s;

    return 0;
}
