#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    vector<int> ans;

    for (int i = 0; i < n; i++) {
        long long remaining = sum - a[i];

        if (a[i] * 1LL * (n - 1) == remaining) {
            ans.push_back(i + 1); // 1-based index
        }
    }

    cout << ans.size() << '\n';

    for (int idx : ans) {
        cout << idx << ' ';
    }

    return 0;
}
