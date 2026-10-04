#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    string x;
    cin >> x;

    int n = x.size();
    long long value = 0;

    for (char c : x) {
        value = (value * 2 + (c - '0')) % MOD;
    }

    long long power = 1;

    for (int i = 0; i < n - 1; i++) {
        power = (power * 2) % MOD;
    }

    long long answer = (value * power) % MOD;

    cout << answer << '\n';

    return 0;
}
