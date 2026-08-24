#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);

    for (int &x : a)
        cin >> x;

    sort(a.rbegin(), a.rend());

    int answer = 0;

    for (int x : a) {
        if (k >= m)
            break;

        k += x - 1;
        answer++;
    }

    if (k >= m)
        cout << answer << '\n';
    else
        cout << -1 << '\n';

    return 0;
}
