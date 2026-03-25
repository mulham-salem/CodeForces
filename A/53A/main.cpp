#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    vector<string> pages(n);
    vector<string> prefix;

    for (int i = 0; i < n; i++) {
        cin >> pages[i];
        if (pages[i].substr(0, s.size()) == s)
            prefix.push_back(pages[i]);
    }

    if (!prefix.empty()) {
        string minPage = prefix[0];
        for (auto p : prefix) {
            if (p < minPage)
                minPage = p;
        }
        cout << minPage << "\n";
    } else {
        cout << s << "\n";
    }

    return 0;
}
