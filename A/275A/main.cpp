#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[3][3];

    int dx[5] = {0, 0, 0, 1, -1};
    int dy[5] = {0, 1, -1, 0, 0};

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> a[i][j];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            int sum = 0;

            for (int k = 0; k < 5; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];

                if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
                    sum += a[ni][nj];
            }

            if (sum % 2 == 1)
                cout << 0 << " ";
            else
                cout << 1 << " ";
        }

        cout << endl;
    }
    return 0;
}
