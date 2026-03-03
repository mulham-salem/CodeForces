#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int n, m;

vector<long long> x, y;
vector<long long> rods;
vector<long long> need;

bool try_solution(int start_index, vector<int>& answer) {

    multiset<pair<long long, int>> S;

    for (int i = 1; i <= m; i++) {
        S.insert({rods[i], i});
    }

    answer.assign(n + 1, -1);

    for (int i = start_index; i <= n; i += 2) {

        auto it = S.lower_bound({need[i], 0});

        if (it == S.end() || it->first != need[i]) {
            return false;
        }

        answer[i] = it->second;
        S.erase(it);
    }

    return true;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    x.resize(n + 1);
    y.resize(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];

    rods.resize(m + 1);

    for (int i = 1; i <= m; i++)
        cin >> rods[i];

    vector<long long> edge(n + 1);

    for (int i = 1; i <= n; i++) {
        int j = (i == n ? 1 : i + 1);
        edge[i] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }

    need.resize(n + 1);

    for (int i = 1; i <= n; i++) {
        int prev = (i == 1 ? n : i - 1);
        need[i] = edge[prev] + edge[i];
    }

    vector<int> answer;

    if (try_solution(1, answer)) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << answer[i] << " ";
    }
    else if (try_solution(2, answer)) {
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << answer[i] << " ";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}