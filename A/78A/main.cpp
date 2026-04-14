#include <bits/stdc++.h>
using namespace std;

// Function to count vowels in a string
int countVowels(const string &s) {
    int cnt = 0;
    for (char c : s) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            cnt++;
        }
    }
    return cnt;
}

int main() {
    string line;
    vector<int> expected = {5, 7, 5};

    for (int i = 0; i < 3; i++) {
        getline(cin, line);
        if (countVowels(line) != expected[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    return 0;
}
