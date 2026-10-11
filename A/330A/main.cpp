#include <iostream>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;

    char a[10][10];
    bool eaten[10][10] = {};

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < r; i++) {
        bool safe = true;

        for (int j = 0; j < c; j++) {
            if (a[i][j] == 'S')
                safe = false;
        }

        if (safe) {
            for (int j = 0; j < c; j++) {
                eaten[i][j] = true;
            }
        }
    }

    for (int j = 0; j < c; j++) {
        bool safe = true;

        for (int i = 0; i < r; i++) {
            if (a[i][j] == 'S')
                safe = false;
        }

        if (safe) {
            for (int i = 0; i < r; i++) {
                eaten[i][j] = true;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (eaten[i][j])
                ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
