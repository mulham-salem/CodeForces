#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPunct(char c) {
    return c == '.' || c == ',' || c == '!' || c == '?';
}

int main() {
    string s;
    getline(cin, s);

    string ans;
    bool pendingSpace = false;

    for (char c : s) {
        if (c == ' ') {
            pendingSpace = true;
        }
        else if (isPunct(c)) {
            while (!ans.empty() && ans.back() == ' ')
                ans.pop_back();

            ans += c;
            ans += ' ';
            pendingSpace = false;
        }
        else { // letter
            if (pendingSpace && !ans.empty() && ans.back() != ' ')
                ans += ' ';

            ans += c;
            pendingSpace = false;
        }
    }

    if (!ans.empty() && ans.back() == ' ')
        ans.pop_back();

    cout << ans << '\n';
    return 0;
}
