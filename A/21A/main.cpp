#include <iostream>
#include <string>
using namespace std;

bool validWord(const string &s, int minLen, int maxLen) {
    if (s.size() < minLen || s.size() > maxLen)
        return false;

    for (char c : s) {
        if (!(isalnum(c) || c == '_'))
            return false;
    }
    return true;
}

int main() {
    string s;
    cin >> s;

    size_t atPos = s.find('@');
    if (atPos == string::npos || s.find('@', atPos + 1) != string::npos) {
        cout << "NO";
        return 0;
    }

    string username = s.substr(0, atPos);
    string rest = s.substr(atPos + 1);

    if (!validWord(username, 1, 16)) {
        cout << "NO";
        return 0;
    }

    string hostname, resource;
    size_t slashPos = rest.find('/');

    if (slashPos != string::npos) {
        if (rest.find('/', slashPos + 1) != string::npos) {
            cout << "NO";
            return 0;
        }

        hostname = rest.substr(0, slashPos);
        resource = rest.substr(slashPos + 1);

        if (!validWord(resource, 1, 16)) {
            cout << "NO";
            return 0;
        }
    } else {
        hostname = rest;
    }

    if (hostname.size() < 1 || hostname.size() > 32) {
        cout << "NO";
        return 0;
    }

    string word = "";
    for (char c : hostname) {
        if (c == '.') {
            if (!validWord(word, 1, 16)) {
                cout << "NO";
                return 0;
            }
            word = "";
        } else {
            if (!(isalnum(c) || c == '_')) {
                cout << "NO";
                return 0;
            }
            word += c;
        }
    }

    if (!validWord(word, 1, 16)) {
        cout << "NO";
        return 0;
    }

    cout << "YES";
    return 0;
}
