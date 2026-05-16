#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> manager(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> manager[i];
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int depth = 1;
        int current = i;

        while (manager[current] != -1) {
            depth++;
            current = manager[current];
        }

        ans = max(ans, depth);
    }

    cout << ans;

    return 0;
}
