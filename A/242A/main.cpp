#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    vector<pair<int, int>> ans;

    for (int c = a; c <= x; c++) {
        for (int d = b; d <= y; d++) {
            if (c > d) {
                ans.push_back({c, d});
            }
        }
    }

    cout << ans.size() << '\n';

    for (auto [c, d] : ans) {
        cout << c << ' ' << d << '\n';
    }

    return 0;
}
