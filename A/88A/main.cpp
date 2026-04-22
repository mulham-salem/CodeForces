#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string, int> note = {
        {"C",0},{"C#",1},{"D",2},{"D#",3},{"E",4},
        {"F",5},{"F#",6},{"G",7},{"G#",8},
        {"A",9},{"B",10},{"H",11}
    };

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    vector<int> a = {note[s1], note[s2], note[s3]};

    vector<vector<int>> perms = {
        {a[0], a[1], a[2]},
        {a[0], a[2], a[1]},
        {a[1], a[0], a[2]},
        {a[1], a[2], a[0]},
        {a[2], a[0], a[1]},
        {a[2], a[1], a[0]}
    };

    for (auto p : perms) {
        int x = p[0], y = p[1], z = p[2];

        int d1 = (y - x + 12) % 12;
        int d2 = (z - y + 12) % 12;

        if (d1 == 4 && d2 == 3) {
            cout << "major";
            return 0;
        }
        if (d1 == 3 && d2 == 4) {
            cout << "minor";
            return 0;
        }
    }

    cout << "strange";
    return 0;
}
