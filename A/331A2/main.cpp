#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> pref(n + 1, 0);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        pref[i + 1] = pref[i] + max(0LL, a[i]);
    }

    long long bestSum = LLONG_MIN;
    int left = 0, right = 1;

    unordered_map<long long, pair<long long, int>> best;

    for (int j = 0; j < n; j++) {
        auto it = best.find(a[j]);

        if (it != best.end()) {
            long long sum = 2 * a[j] + pref[j] - it->second.first;

            if (sum > bestSum) {
                bestSum = sum;
                left = it->second.second;
                right = j;
            }
        }

        long long currentPref = pref[j + 1];

        if (best.find(a[j]) == best.end() ||
            currentPref < best[a[j]].first) {
            best[a[j]] = {currentPref, j};
        }
    }

    vector<int> cut;

    for (int k = 0; k < n; k++) {
        if (k < left || k > right ||
            (k > left && k < right && a[k] < 0)) {
            cut.push_back(k + 1);
        }
    }

    cout << bestSum << " " << cut.size() << "\n";

    for (int i = 0; i < (int)cut.size(); i++) {
        cout << cut[i] << " ";
    }

    cout << "\n";

    return 0;
}
