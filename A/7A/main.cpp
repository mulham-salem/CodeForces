#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main()
{
    char board[8][8];

    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];

    int rowCount = 0, colCount = 0;
    bool allBlack = true;

    for (int i = 0; i < 8; i++)
    {
        allBlack = true;
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] != 'B') {
                allBlack = false;
                break;
            }
        }
        if (allBlack) rowCount++;
    }

    for (int j = 0; j < 8; j++)
    {
        allBlack = true;
        for (int i = 0; i < 8; i++)
        {
            if (board[i][j] != 'B') {
                allBlack = false;
                break;
            }
        }
        if (allBlack) colCount++;
    }

    if (rowCount > 0) {
        if (rowCount == 8)
            cout << 8;
        else
            cout << rowCount + colCount;
    } else {
        cout << colCount;
    }


    return 0;
}
