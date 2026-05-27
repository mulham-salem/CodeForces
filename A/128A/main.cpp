#include <bits/stdc++.h>
using namespace std;

struct State {
    int x, y, t;
};

bool hasStatue(vector<string>& board, int x, int y, int t) {
    int row = x - t;

    if (row >= 0 && board[row][y] == 'S')
        return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board(8);

    for (int i = 0; i < 8; i++)
        cin >> board[i];

    queue<State> q;
    bool vis[8][8][9] = {};

    q.push({7, 0, 0});
    vis[7][0][0] = true;

    int dx[] = {-1,-1,-1,0,0,0,1,1,1};
    int dy[] = {-1,0,1,-1,0,1,-1,0,1};

    while (!q.empty()) {
        auto [x, y, t] = q.front();
        q.pop();

        // if statue already here -> dead
        if (hasStatue(board, x, y, t))
            continue;

        // after enough time all statues disappear
        if (t >= 8) {
            cout << "WIN\n";
            return 0;
        }

        for (int k = 0; k < 9; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8)
                continue;

            // statue exists now
            if (hasStatue(board, nx, ny, t))
                continue;

            // statue moves onto cell next turn
            if (hasStatue(board, nx, ny, t + 1))
                continue;

            if (!vis[nx][ny][min(t + 1, 8)]) {
                vis[nx][ny][min(t + 1, 8)] = true;
                q.push({nx, ny, t + 1});
            }
        }
    }

    cout << "LOSE\n";

    return 0;
}
