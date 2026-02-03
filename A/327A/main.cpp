#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt1 = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x == 1) {
            cnt1++;
            a[i] = -1;
        } else {
            a[i] = 1;
        }
    }

    int current = 0, best = 0;
    for (int num : a) {
        current = max(num, current + num);
        best = max(best, current);
    }

    int sum;
    if (best == 0)
        sum = cnt1 - 1;
    else
        sum = cnt1 + best;

    cout << sum;
    return 0;
}
