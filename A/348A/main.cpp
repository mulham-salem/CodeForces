#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long sum = 0;
    long long maxA = 0;

    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        sum += a;
        maxA = max(maxA, a);
    }

    long long answer = max(maxA, (sum + n - 2) / (n - 1));

    cout << answer << '\n';

    return 0;
}
