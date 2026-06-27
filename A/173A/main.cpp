#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64 n;
    cin >> n;

    string A, B;
    cin >> A >> B;

    int m = A.size(), k = B.size();
    int g = __gcd(m, k);
    int64 l = 1LL * m / g * k;

    auto win = [](char x, char y) {
        return (x == 'R' && y == 'S') ||
               (x == 'S' && y == 'P') ||
               (x == 'P' && y == 'R');
    };

    int64 nikeLose = 0, polyLose = 0;

    for (int64 i = 0; i < l; i++) {
        char a = A[i % m];
        char b = B[i % k];

        if (win(a, b))
            polyLose++;
        else if (win(b, a))
            nikeLose++;
    }

    int64 full = n / l;
    int64 rem = n % l;

    int64 ansNike = nikeLose * full;
    int64 ansPoly = polyLose * full;

    for (int64 i = 0; i < rem; i++) {
        char a = A[i % m];
        char b = B[i % k];

        if (win(a, b))
            ansPoly++;
        else if (win(b, a))
            ansNike++;
    }

    cout << ansNike << " " << ansPoly << '\n';

    return 0;
}
