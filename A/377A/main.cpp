#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int keep;
vector<string> maze;
vector<vector<bool>> visited;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {

    if (x < 0 || x >= n || y < 0 || y >= m)
        return;

    if (maze[x][y] == '#' || visited[x][y])
        return;

    visited[x][y] = true;

    if (keep > 0) {
        keep--;
    }
    else {
        maze[x][y] = 'X';
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        dfs(nx, ny);
    }
}

int main() {

    cin >> n >> m >> k;

    maze.resize(n);
    visited.assign(n, vector<bool>(m, false));

    int totalEmpty = 0;

    for (int i = 0; i < n; i++) {
        cin >> maze[i];

        for (int j = 0; j < m; j++) {
            if (maze[i][j] == '.') {
                totalEmpty++;
            }
        }
    }

    keep = totalEmpty - k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (maze[i][j] == '.') {
                dfs(i, j);
                break;
            }
        }

        if (keep == 0)
            break;
    }

    for (int i = 0; i < n; i++) {
        cout << maze[i] << '\n';
    }

    return 0;
}
