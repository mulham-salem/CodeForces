#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char board[n][m];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> board[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '-')
                continue;
            else {
                if ( ( i + j ) % 2 == 0 )
                    board[i][j] = 'B';
                else
                    board[i][j] = 'W';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }

    return 0;
}
