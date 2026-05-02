#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int dot = s.find('.');
    string integerPart = s.substr(0, dot);
    string fractionalPart = s.substr(dot + 1);

    // If last digit of integer part is 9
    if (integerPart.back() == '9') {
        cout << "GOTO Vasilisa.\n";
        return 0;
    }

    // Check first digit of fractional part
    if (fractionalPart[0] >= '5') {
        // Add 1 to integer part
        int n = integerPart.size();
        int i = n - 1;

        // Simple addition (no carry issue beyond this digit since it's not 9)
        integerPart[i]++;

        cout << integerPart << "\n";
    } else {
        cout << integerPart << "\n";
    }

    return 0;
}
