#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> neg, pos, zero;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) neg.push_back(a[i]);
        else if (a[i] > 0) pos.push_back(a[i]);
        else zero.push_back(a[i]);
    }

    vector<int> set1, set2, set3;

    // Set 1: one negative
    set1.push_back(neg[0]);

    // Set 3: all zeros
    for (int z : zero) set3.push_back(z);

    int idx = 1; // next negative index to use

    // If remaining negatives count is odd, move one more to set3
    if ((neg.size() - 1) % 2 != 0) {
        set3.push_back(neg[idx]);
        idx++;
    }

    // Set 2: all remaining negatives + all positives
    for (int i = idx; i < (int)neg.size(); i++) set2.push_back(neg[i]);
    for (int p : pos) set2.push_back(p);

    // Print
    cout << set1.size();
    for (int x : set1) cout << " " << x;
    cout << "\n";

    cout << set2.size();
    for (int x : set2) cout << " " << x;
    cout << "\n";

    cout << set3.size();
    for (int x : set3) cout << " " << x;
    cout << "\n";

    return 0;
}
