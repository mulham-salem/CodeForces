#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string result = "";

    for (char c : s) {
        if (!result.empty() && result.back() == c) {
            result.pop_back(); // remove the pair
        } else {
            result.push_back(c); // add character
        }
    }

    cout << result << endl;
    return 0;
}
