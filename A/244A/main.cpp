#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(k);
    vector<bool> used(n * k + 1, false);
    vector<vector<int>> groups(k);

    for (int i = 0; i < k; i++) {
        cin >> a[i];

        groups[i].push_back(a[i]);
        used[a[i]] = true;
    }

    int current = 1;

    for (int i = 0; i < k; i++) {
        while ((int)groups[i].size() < n) {
            while (used[current])
                current++;

            groups[i].push_back(current);
            used[current] = true;
            current++;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int x : groups[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }

    return 0;
}
