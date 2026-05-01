#include <bits/stdc++.h>
using namespace std;

vector<array<int,6>> rotations = {
    {0,1,2,3,4,5},
    {0,1,4,5,3,2},
    {0,1,3,2,5,4},
    {0,1,5,4,2,3},

    {1,0,2,3,5,4},
    {1,0,4,5,2,3},
    {1,0,3,2,4,5},
    {1,0,5,4,3,2},

    {2,3,1,0,4,5},
    {2,3,4,5,0,1},
    {2,3,0,1,5,4},
    {2,3,5,4,1,0},

    {3,2,1,0,5,4},
    {3,2,4,5,1,0},
    {3,2,0,1,4,5},
    {3,2,5,4,0,1},

    {4,5,2,3,1,0},
    {4,5,1,0,3,2},
    {4,5,3,2,0,1},
    {4,5,0,1,2,3},

    {5,4,2,3,0,1},
    {5,4,1,0,2,3},
    {5,4,3,2,1,0},
    {5,4,0,1,3,2}
};

string rotateCube(const string &s, const array<int,6> &r) {
    string t(6, ' ');
    for (int i = 0; i < 6; i++) {
        t[i] = s[r[i]];
    }
    return t;
}

string canonical(string s) {
    string best = "ZZZZZZ";
    for (auto &r : rotations) {
        string t = rotateCube(s, r);
        if (t < best) best = t;
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    set<string> st;

    do {
        st.insert(canonical(s));
    } while (next_permutation(s.begin(), s.end()));

    cout << st.size() << "\n";

    return 0;
}
