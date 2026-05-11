#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string t) {
    return t[0] == t[4] && t[1] == t[3];
}

int main() {
    string s;
    cin >> s;

    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));

    while (true) {
        // move to next minute
        m++;

        if (m == 60) {
            m = 0;
            h++;
        }

        if (h == 24) {
            h = 0;
        }

        // build time string
        string hh = (h < 10 ? "0" : "") + to_string(h);
        string mm = (m < 10 ? "0" : "") + to_string(m);

        string current = hh + ":" + mm;

        if (isPalindrome(current)) {
            cout << current << '\n';
            break;
        }
    }

    return 0;
}
