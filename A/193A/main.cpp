#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n, m;
vector<string> grid;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

vector<vector<bool>> vis;

void dfs(int x, int y) {
    vis[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx >= 0 && nx < n &&
            ny >= 0 && ny < m &&
            !vis[nx][ny] &&
            grid[nx][ny] == '#') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;

    grid.resize(n);

    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (char c : grid[i])
            if (c == '#')
                total++;
    }

    if (total < 3) {
        cout << -1 << '\n';
        return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] != '#')
                continue;

            // Remove this cell temporarily
            grid[i][j] = '.';

            vis.assign(n, vector<bool>(m, false));

            int sx = -1, sy = -1;

            // Find any remaining painted cell
            for (int x = 0; x < n && sx == -1; x++) {
                for (int y = 0; y < m; y++) {
                    if (grid[x][y] == '#') {
                        sx = x;
                        sy = y;
                        break;
                    }
                }
            }

            if (sx != -1)
                dfs(sx, sy);

            int visited = 0;
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < m; y++) {
                    if (grid[x][y] == '#' && vis[x][y])
                        visited++;
                }
            }

            if (visited != total - 1) {
                cout << 1 << '\n';
                return 0;
            }

            // Restore the cell
            grid[i][j] = '#';
        }
    }

    cout << 2 << '\n';

    return 0;
}
