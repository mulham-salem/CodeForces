#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int toHouse[N];
int inDegree[N];
int diameterPipe[N];

int main() {
    int n, p;
    cin >> n >> p;

    for (int i = 0; i < p; i++) {
        int a, b, d;
        cin >> a >> b >> d;

        toHouse[a] = b;
        inDegree[b]++;
        diameterPipe[a] = d;
    }

    vector<tuple<int, int, int>> ans;

    for (int i = 1; i <= n; i++) {

        // Tank
        if (toHouse[i] != 0 && inDegree[i] == 0) {

            int current = i;
            int mn = INT_MAX;

            while (toHouse[current] != 0) {
                mn = min(mn, diameterPipe[current]);
                current = toHouse[current];
            }

            ans.push_back({i, current, mn});
        }
    }

    cout << ans.size() << '\n';

    for (auto [tank, tap, d] : ans) {
        cout << tank << " " << tap << " " << d << '\n';
    }

    return 0;
}
