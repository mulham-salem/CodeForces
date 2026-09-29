#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s[0] != '-') {
        cout << s << '\n';
        return 0;
    }

    // Delete last digit
    string a = s.substr(0, s.size() - 1);

    // Delete digit before last
    string b = s.substr(0, s.size() - 2) + s.back();

    cout << max({stoll(s), stoll(a), stoll(b)}) << '\n';

    return 0;
}
