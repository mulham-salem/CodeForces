#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    cin >> n >> s;

    int firstHalf = 0, secondHalf = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] != '4' && s[i] != '7') {
            cout << "NO\n";
            return 0;
        }

        if (i < n / 2)
            firstHalf += s[i] - '0';
        else
            secondHalf += s[i] - '0';
    }

    cout << (firstHalf == secondHalf ? "YES" : "NO") << '\n';

    return 0;
}
