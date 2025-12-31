#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int lastChild = 1;
    int maxTimes = 0;

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;

        int times = (a + m-1) / m;

        if (times >= maxTimes) {
            maxTimes = times;
            lastChild = i;
        }
    }

    cout << lastChild;

    return 0;
}
