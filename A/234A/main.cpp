#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    string s;

    cin >> n >> s;

    int half = n / 2;

    for (int i = 0; i < half; i++) {
        int a = i;
        int b = i + half;

        // R on the left and L on the right is forbidden
        if (s[a] == 'R' && s[b] == 'L') {
            swap(a, b);
        }

        cout << a + 1 << " " << b + 1 << '\n';
    }

    return 0;
}
