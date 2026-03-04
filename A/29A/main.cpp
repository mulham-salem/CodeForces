#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> camels;
    camels.reserve(n);

    for (int i = 0; i < n; i++) {
        int x, d;
        cin >> x >> d;
        camels.emplace_back(x, d);
    }

    int sz = camels.size();

    for (int i = 0; i < sz; i++) {
        auto [x1, d1] = camels[i];
        int target1 = x1 + d1;

        for (int j = i + 1; j < sz; j++) {
            auto [x2, d2] = camels[j];
            int target2 = x2 + d2;

            if (target1 == x2 && target2 == x1) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
    return 0;
}
