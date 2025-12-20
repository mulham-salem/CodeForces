#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string s = to_string(n);
    int count = 0;

    for (char c : s) {
        if (c == '4' || c == '7')
            count++;
    }

    if (count == 0) {
        cout << "NO";
        return 0;
    }

    string cnt = to_string(count);
    for (char c : cnt) {
        if (c != '4' && c != '7') {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
    return 0;
}
