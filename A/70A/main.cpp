#include <iostream>
using namespace std;

const int MOD = 1000003;

int main() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
    } else {
        long long ans = 1;
        for (int i = 0; i < n-1; i++) {
            ans = (ans * 3) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}
