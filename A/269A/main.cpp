#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    long long max_p = 0;

    for (int i = 0; i < n; ++i) {
        long long k, a;
        cin >> k >> a;

        long long count = 0;
        long long capacity = 1;

        while (capacity < a) {
            capacity *= 4;
            count++;
        }

        if (count == 0) {
            count = 1;
        }

        long long required_p = k + count;

        max_p = max(max_p, required_p);
    }

    cout << max_p << "\n";

    return 0;
}
