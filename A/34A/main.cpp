#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minDiff = INT_MAX;
    int ans1 = 0, ans2 = 0;

    for (int i = 0; i < n-1; i++) {
        int diff = abs(a[i] - a[i+1]);
        if (diff < minDiff) {
            minDiff = diff;
            ans1 = i + 1;
            ans2 = i + 2;
        }
    }

    int diff = abs(a[n-1] - a[0]);
    if (diff < minDiff) {
        ans1 = n;
        ans2 = 1;
    }

    cout << ans1 << " " << ans2 << endl;

    return 0;
}
