#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;  // 80-bit string

    unordered_map<string, char> mp;

    // read mapping for digits 0..9
    for (int i = 0; i < 10; i++) {
        string code;
        cin >> code;
        mp[code] = char('0' + i);
    }

    string ans = "";

    // split into 8 chunks of 10 characters
    for (int i = 0; i < 8; i++) {
        string chunk = s.substr(i * 10, 10);
        ans += mp[chunk];
    }

    cout << ans << "\n";

    return 0;
}
