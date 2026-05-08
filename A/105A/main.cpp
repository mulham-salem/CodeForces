#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    double k;

    cin >> n >> m >> k;

    map<string, int> skills;

    for (int i = 0; i < n; i++) {
        string name;
        int exp;

        cin >> name >> exp;

        int newExp = (int)floor(exp * k + 1e-9);

        if (newExp >= 100) {
            skills[name] = newExp;
        }
    }

    for (int i = 0; i < m; i++) {
        string name;
        cin >> name;

        if (!skills.count(name)) {
            skills[name] = 0;
        }
    }

    cout << skills.size() << '\n';

    for (auto &skill : skills) {
        cout << skill.first << " " << skill.second << '\n';
    }

    return 0;
}
