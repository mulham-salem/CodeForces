#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<int> distinctValues;

    vector<int> previous;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        vector<int> current;

        // Subarray containing only x
        current.push_back(x);

        // Extend all previous subarrays by x
        for (int v : previous) {
            int newValue = v | x;

            // Avoid duplicate consecutive values
            if (newValue != current.back()) {
                current.push_back(newValue);
            }
        }

        // Add all results to the global set
        for (int v : current) {
            distinctValues.insert(v);
        }

        previous = current;
    }

    cout << distinctValues.size() << '\n';

    return 0;
}
