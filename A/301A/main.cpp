#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int size = 2 * n - 1;

    long long sum = 0;
    int negativeCount = 0;
    int minAbs = 1000000000;

    for (int i = 0; i < size; i++) {
        int x;
        cin >> x;

        sum += abs(x);

        if (x < 0)
            negativeCount++;

        minAbs = min(minAbs, abs(x));
    }

    if (n % 2 == 1) {
        cout << sum << endl;
    }
    else if (negativeCount % 2 == 0) {
        cout << sum << endl;
    }
    else {
        cout << sum - 2LL * minAbs << endl;
    }

    return 0;
}
