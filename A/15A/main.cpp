#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;

    vector<pair<int, int>> cottage;

    for (int i = 0; i < n; i++) {
        int x, a;
        cin >> x >> a;
        cottage.push_back({x, a});
    }

    sort(cottage.begin(), cottage.end());

    vector<pair<int,int>> segments;

    for (auto c : cottage) {
        int left  = 2*c.first - c.second; // 2x - a
        int right = 2*c.first + c.second; // 2x + a
        segments.push_back({left, right});
    }

    int amount_of_positions = 2;
    int T = 2 * t;

    for (int i = 0; i < n-1; i++) {
        int gap = segments[i+1].first - segments[i].second;

        if (T < gap) {
            amount_of_positions += 2;
        }
        else if (T == gap) {
            amount_of_positions += 1;
        }
    }

    cout << amount_of_positions;
    return 0;
}
