#include <iostream>
#include <vector>
#include <climits>
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

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                long long sum = a[i] + a[j]
                              + pref[j] - pref[i + 1];

                if (sum > bestSum) {
                    bestSum = sum;
                    left = i;
                    right = j;
                }
            }
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
