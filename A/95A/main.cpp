#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

// Convert a string to lowercase for case-insensitive comparison
string toLower(const string& s) {
    string res = s;
    for (char& c : res) {
        c = tolower(c);
    }
    return res;
}

int main() {
    int n;
    cin >> n;

    vector<string> forbidden(n);
    for (int i = 0; i < n; ++i) {
        cin >> forbidden[i];
        forbidden[i] = toLower(forbidden[i]); // store in lowercase
    }

    string w;
    cin >> w;

    char lucky;
    cin >> lucky;

    int len = w.size();
    string w_lower = toLower(w);

    vector<bool> covered(len, false);

    // Find all occurrences of forbidden substrings in w_lower
    for (const string& pat : forbidden) {
        int pat_len = pat.size();
        for (int i = 0; i + pat_len <= len; ++i) {
            if (w_lower.substr(i, pat_len) == pat) {
                for (int j = i; j < i + pat_len; ++j) {
                    covered[j] = true;
                }
            }
        }
    }

    // Result string
    string result = w;

    // Replace covered characters to maximize lucky letter occurrences
    char lucky_lower = tolower(lucky);
    char opposite_lucky;
    if (lucky_lower == 'a') opposite_lucky = 'b';
    else opposite_lucky = 'a';

    for (int i = 0; i < len; ++i) {
        if (covered[i]) {
            char current_lower = tolower(w[i]);
            if (current_lower != lucky_lower) {
                // We can replace with lucky letter
                if (isupper(w[i])) {
                    result[i] = toupper(lucky);
                } else {
                    result[i] = lucky;
                }
            } else {
                char lucky_same_case = (isupper(w[i]) ? toupper(lucky) : tolower(lucky));
                if (current_lower == lucky_lower) {
                    // originally lucky, must replace with smallest non-lucky in same case
                    if (isupper(w[i])) {
                        // uppercase, smallest non-lucky: 'A' if 'A' != lucky_same_case, else 'B'
                        if (lucky_same_case != 'A') result[i] = 'A';
                        else result[i] = 'B';
                    } else {
                        // lowercase, smallest non-lucky: 'a' if 'a' != lucky_same_case, else 'b'
                        if (lucky_same_case != 'a') result[i] = 'a';
                        else result[i] = 'b';
                    }
                } else {
                    // originally non-lucky, replace with lucky in same case
                    result[i] = lucky_same_case;
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}
