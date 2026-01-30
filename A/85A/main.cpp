#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "a\na\nb\nb" << endl;
        return 0;
    }

    vector<string> grid(4, string(n, ' '));

    if (n % 2 != 0) {
        grid[0][0] = grid[1][0] = 'a';
        for (int i = 1; i < n; i += 2) {
            grid[0][i] = grid[0][i+1] = (i % 4 == 1) ? 'b' : 'c';
            grid[1][i] = grid[1][i+1] = (i % 4 == 1) ? 'd' : 'e';
        }
    } else {
        grid[0][0] = grid[1][0] = 'a';
        grid[0][n-1] = grid[1][n-1] = 'z';
        for (int i = 1; i < n - 1; i += 2) {
            grid[0][i] = grid[0][i+1] = (i % 4 == 1) ? 'b' : 'c';
            grid[1][i] = grid[1][i+1] = (i % 4 == 1) ? 'd' : 'e';
        }
    }

    if (n % 2 != 0) {
        for (int i = 0; i < n - 1; i += 2) {
            grid[2][i] = grid[2][i+1] = (i % 4 == 0) ? 'x' : 'y';
            grid[3][i] = grid[3][i+1] = (i % 4 == 0) ? 'w' : 'v';
        }
        grid[2][n-1] = grid[3][n-1] = 'u';
    } else {
        for (int i = 0; i < n; i += 2) {
            grid[2][i] = grid[2][i+1] = (i % 4 == 0) ? 'x' : 'y';
            grid[3][i] = grid[3][i+1] = (i % 4 == 0) ? 'w' : 'v';
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << grid[i] << endl;
    }

    return 0;
}
