#include <bits/stdc++.h>
using namespace std;

int main() {
    int p;
    cin >> p;

    int n = p - 1;
    int answer = n;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;

            answer -= answer / i;
        }
    }

    if (n > 1)
        answer -= answer / n;

    cout << answer << '\n';

    return 0;
}
