#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int len = s[0].size();
    int answer = 0;

    for (int pos = 0; pos < len; pos++) {
        char c = s[0][pos];

        bool same = true;
        for (int i = 1; i < n; i++) {
            if (s[i][pos] != c) {
                same = false;
                break;
            }
        }

        if (!same) break;
        answer++;
    }

    cout << answer << '\n';
    return 0;
}
