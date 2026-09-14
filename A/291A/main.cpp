#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;

        if (id != 0)
            mp[id]++;
    }

    int answer = 0;

    for (auto x : mp) {
        if (x.second > 2) {
            cout << -1 << endl;
            return 0;
        }

        if (x.second == 2)
            answer++;
    }

    cout << answer << endl;

    return 0;
}
