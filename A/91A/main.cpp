#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    vector<vector<int>> posList(26);
    for (int i = 0; i < (int)s1.size(); i++) {
        posList[s1[i] - 'a'].push_back(i);
    }

    for (char c : s2) {
        if (posList[c - 'a'].empty()) {
            cout << -1 << "\n";
            return 0;
        }
    }

    int count = 1;
    int pos = -1;

    for (char c : s2) {
        auto &vec = posList[c - 'a'];

        auto it = upper_bound(vec.begin(), vec.end(), pos);

        if (it != vec.end()) {
            pos = *it;
        } else {
            count++;
            pos = vec[0];
        }
    }

    cout << count << "\n";
    return 0;
}
