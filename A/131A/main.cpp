#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool caps = true;

    // Check if all characters except the first are uppercase
    for (int i = 1; i < s.size(); i++) {
        if (islower(s[i])) {
            caps = false;
            break;
        }
    }

    // If condition is true, change case of all letters
    if (caps) {
        for (char &c : s) {
            if (islower(c))
                c = toupper(c);
            else
                c = tolower(c);
        }
    }

    cout << s;

    return 0;
}
