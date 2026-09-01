#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;

    long long current_height = 0;

    while (m--) {
        int w;
        long long h;
        cin >> w >> h;

        long long base_height = a[w-1];

        long long bottom_height = max(current_height, base_height);

        cout << bottom_height << "\n";

        current_height = bottom_height + h;
    }

    return 0;
}
