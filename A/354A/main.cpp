#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, l, r, Ql, Qr;
    cin >> n >> l >> r >> Ql >> Qr;

    vector<int> w(n);
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        cin >> w[i];
        totalWeight += w[i];
    }

    int leftWeight = 0;
    int answer = 1e9;

    for (int leftCount = 0; leftCount <= n; leftCount++) {
        int rightCount = n - leftCount;

        int rightWeight = totalWeight - leftWeight;

        int energy = leftWeight * l + rightWeight * r;

        if (leftCount > rightCount + 1) {
            energy += (leftCount - rightCount - 1) * Ql;
        }

        if (rightCount > leftCount + 1) {
            energy += (rightCount - leftCount - 1) * Qr;
        }

        answer = min(answer, energy);

        if (leftCount < n) {
            leftWeight += w[leftCount];
        }
    }

    cout << answer << '\n';

    return 0;
}
