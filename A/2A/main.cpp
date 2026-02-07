#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> rounds;

    map<string, int> total;

    for (int i = 0; i < n; i++)
    {
        string name;
        int score;
        cin >> name >> score;

        rounds.push_back({name, score});
        total[name] += score;
    }

    auto maxValue = max_element(total.begin(), total.end(),
    [](const auto& a, const auto& b) {
        return a.second < b.second;
    });

    int maxScore = maxValue->second;

    map<string, int> current;

    for (auto &r : rounds)
    {
        current[r.first] += r.second;

        if (current[r.first] >= maxScore && total[r.first] == maxScore) {
            cout << r.first;
            break;
        }
    }

    return 0;
}
