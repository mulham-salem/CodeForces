#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool used[3002] = {false};

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        used[x] = true;
    }

    for (int i = 1; i <= 3001; i++) {
        if (!used[i]) {
            cout << i << "\n";
            break;
        }
    }

    return 0;
}
