#include <bits/stdc++.h>
using namespace std;

int main() {

    int a;
    cin >> a;

    string s;
    cin >> s;

    int n = s.size();

    int maxSum = 9 * n;

    vector<long long> freq(maxSum + 1, 0);

    for (int i = 0; i < n; i++) {

        int sum = 0;

        for (int j = i; j < n; j++) {

            sum += s[j] - '0';

            freq[sum]++;
        }
    }

    long long total = 1LL * n * (n + 1) / 2;

    long long ans = 0;

    if (a == 0) {

        long long zero = freq[0];

        ans = 2 * zero * total - zero * zero;

    }
    else {

        for (int x = 1; x <= maxSum; x++) {

            if (a % x == 0) {

                int y = a / x;

                if (y <= maxSum) {

                    ans += freq[x] * freq[y];
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
