#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool possible = true;
    for (int i = k; i < n; i++) {
        if (a[i] != a[k - 1]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }


    int steps = 0;
    for (int i = k - 2; i >= 0; i--) {
        if (a[i] != a[k - 1]) {
            steps = i + 1;
            break;
        }
    }

    cout << steps << endl;

    return 0;
}
