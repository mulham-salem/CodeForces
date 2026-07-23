#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s;
    cin >> s;

    char mx = *max_element(s.begin(), s.end());

    for (char c : s) {
        if (c == mx)
            cout << c;
    }

    return 0;
}
