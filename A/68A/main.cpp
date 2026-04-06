#include <bits/stdc++.h>
using namespace std;

int main() {
    int p[4], a, b;
    cin >> p[0] >> p[1] >> p[2] >> p[3] >> a >> b;

    vector<vector<int>> perms;

    // generate all permutations
    vector<int> v = {p[0], p[1], p[2], p[3]};

    sort(v.begin(), v.end());

    do {
        perms.push_back(v);
    } while (next_permutation(v.begin(), v.end()));

    int answer = 0;

    // try every x
    for (int x = a; x <= b; x++) {
        int good = 0;

        // try every permutation
        for (auto &perm : perms) {
            int cur = x;

            for (int i = 0; i < 4; i++) {
                cur %= perm[i];
            }

            if (cur == x) {
                good++;
            }
        }

        if (good >= 7) {
            answer++;
        }
    }

    cout << answer << endl;
    return 0;
}
