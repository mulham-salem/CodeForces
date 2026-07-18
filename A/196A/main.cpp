#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<char> mx(n);

    mx[n - 1] = s[n - 1];
    for (int i = n - 2; i >= 0; i--)
        mx[i] = max(s[i], mx[i + 1]);

    for (int i = 0; i < n; i++)
        if (s[i] == mx[i])
            cout << s[i];

    return 0;
}
