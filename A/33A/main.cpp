#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;

    vector<long long> rowMin(m + 1, 1e18);

    for (int i = 0; i < n; i++) {
        int r;
        long long c;
        cin >> r >> c;

        rowMin[r] = min(rowMin[r], c);
    }

    long long sum = 0;

    for (int i = 1; i <= m; i++) {
        sum += rowMin[i];
    }

    cout << min(sum, k) << endl;

    return 0;
}
