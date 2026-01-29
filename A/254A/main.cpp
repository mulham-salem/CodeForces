#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream in("input.txt");
    ofstream out("output.txt");

    int n;
    in >> n;

    vector<int> pos[5001];

    for (int i = 1; i <= 2 * n; i++) {
        int x;
        in >> x;
        pos[x].push_back(i);
    }

    for (int i = 1; i <= 5000; i++) {
        if (pos[i].size() % 2) {
            out << -1;
            return 0;
        }
    }

    for (int i = 1; i <= 5000; i++) {
        for (int j = 0; j < pos[i].size(); j += 2) {
            out << pos[i][j] << " " << pos[i][j + 1] << "\n";
        }
    }

    return 0;
}
