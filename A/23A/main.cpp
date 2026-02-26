#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    int maxLength = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {

            int length = 0;

            while (i + length < n && j + length < n
                   && s[i + length] == s[j + length]) {
                length++;
                maxLength = max(maxLength, length);
            }
        }
    }

    cout << maxLength << endl;

    return 0;
}
