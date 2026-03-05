#include <iostream>

using namespace std;

long long power(long long x, int n) {
    long long res = 1;

    for (int i = 0; i < n; i++) {
        res *= x;

        if (abs(res) > 2000)
            return res;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, n;
    cin >> A >> B >> n;

    if (A == 0) {
        if (B == 0) cout << 1 << "\n";
        else cout << "No solution\n";
        return 0;
    }

    for (int X = -1000; X <= 1000; X++) {
        long long val = power(X, n);

        if (A * val == B) {
            cout << X << "\n";
            return 0;
        }
    }

    cout << "No solution\n";
}
