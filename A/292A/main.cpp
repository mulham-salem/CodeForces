#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long finish = 0;
    long long maxQueue = 0;

    for (int i = 0; i < n; i++) {
        long long t, c;
        cin >> t >> c;

        long long queue = max(0LL, finish - t) + c;

        maxQueue = max(maxQueue, queue);

        finish = max(finish, t) + c;
    }

    cout << finish << " " << maxQueue << endl;

    return 0;
}
