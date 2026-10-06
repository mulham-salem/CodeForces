#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    // Maximum number of dances is n + m - 1
    cout << n + m - 1 << endl;

    // First, boy 1 dances with all girls
    for (int j = 1; j <= m; j++) {
        cout << 1 << " " << j << endl;
    }

    // Then, girl 1 dances with all remaining boys
    for (int i = 2; i <= n; i++) {
        cout << i << " " << 1 << endl;
    }

    return 0;
}
