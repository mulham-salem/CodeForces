#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first >> p[i].second;
    }

    int central = 0;

    for (int i = 0; i < n; i++) {
        bool left = false, right = false, up = false, down = false;

        int x = p[i].first;
        int y = p[i].second;

        for (int j = 0; j < n; j++) {
            if (p[j].second == y && p[j].first < x)
                left = true;
            else if (p[j].second == y && p[j].first > x)
                right = true;
            else if (p[j].first == x && p[j].second > y)
                up = true;
            else if (p[j].first == x && p[j].second < y)
                down = true;
        }

        if (left && right && up && down)
            central++;
    }

    cout << central;
    return 0;
}
