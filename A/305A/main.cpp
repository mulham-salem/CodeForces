#include <bits/stdc++.h>
using namespace std;

int getMask(int x) {
    int mask = 0;

    if (x % 10 != 0)
        mask |= 1;

    if ((x / 10) % 10 != 0)
        mask |= 2;

    if ((x / 100) % 10 != 0)
        mask |= 4;

    return mask;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int>> numbers(8);

    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;

        int mask = getMask(x);
        numbers[mask].push_back(x);
    }

    int bestCount = 0;
    int bestSet = 0;

    // Try every subset of the 8 masks
    for (int subset = 0; subset < (1 << 8); subset++) {
        bool valid = true;

        for (int i = 0; i < 8; i++) {
            if (!(subset & (1 << i)))
                continue;

            for (int j = i + 1; j < 8; j++) {
                if (!(subset & (1 << j)))
                    continue;

                if ((i & j) != 0) {
                    valid = false;
                    break;
                }
            }

            if (!valid)
                break;
        }

        if (!valid)
            continue;

        int total = numbers[0].size();

        for (int i = 1; i < 8; i++) {
            if (subset & (1 << i)) {
                // From every non-zero mask, we can take only ONE number
                if (!numbers[i].empty())
                    total++;
            }
        }

        if (total > bestCount) {
            bestCount = total;
            bestSet = subset;
        }
    }

    cout << bestCount << '\n';

    // mask 0: take all
    for (int x : numbers[0])
        cout << x << ' ';

    // Other masks: take only one
    for (int mask = 1; mask < 8; mask++) {
        if (bestSet & (1 << mask)) {
            cout << numbers[mask][0] << ' ';
        }
    }

    cout << '\n';

    return 0;
}
