#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int answer = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int luckyCount = 0;

        while (x > 0) {
            int digit = x % 10;

            if (digit == 4 || digit == 7) {
                luckyCount++;
            }

            x /= 10;
        }

        if (luckyCount <= k) {
            answer++;
        }
    }

    cout << answer << '\n';

    return 0;
}
