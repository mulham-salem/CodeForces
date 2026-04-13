#include <bits/stdc++.h>
using namespace std;

vector<string> names = {
    "Anka", "Chapay", "Cleo", "Troll",
    "Dracul", "Snowy", "Hexadecimal"
};

map<string, int> id;
int likeArr[7][7];

int team[7];

long long a, b, c;

long long best_diff = LLONG_MAX;
long long best_like = 0;


int calc_like() {
    int total = 0;
    for (int t = 0; t < 3; t++) {
        vector<int> members;
        for (int i = 0; i < 7; i++) {
            if (team[i] == t)
                members.push_back(i);
        }
        for (int i : members) {
            for (int j : members) {
                if (i != j && likeArr[i][j])
                    total++;
            }
        }
    }
    return total;
}


void solve(int i) {
    if (i == 7) {
        int cnt[3] = {0};
        for (int j = 0; j < 7; j++)
            cnt[team[j]]++;

        if (cnt[0] == 0 || cnt[1] == 0 || cnt[2] == 0)
            return;

        vector<long long> exps;

        exps.push_back(a / cnt[0]);
        exps.push_back(b / cnt[1]);
        exps.push_back(c / cnt[2]);

        long long mx = *max_element(exps.begin(), exps.end());
        long long mn = *min_element(exps.begin(), exps.end());

        long long diff = mx - mn;

        int likes = calc_like();

        if (diff < best_diff) {
            best_diff = diff;
            best_like = likes;
        } else if (diff == best_diff) {
            best_like = max(best_like, (long long)likes);
        }

        return;
    }

    for (int t = 0; t < 3; t++) {
        team[i] = t;
        solve(i + 1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < 7; i++) {
        id[names[i]] = i;
    }

    int n;
    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++) {
        string p, likes_word, q;
        cin >> p >> likes_word >> q;
        likeArr[id[p]][id[q]] = 1;
    }

    cin >> a >> b >> c;

    solve(0);

    cout << best_diff << " " << best_like << "\n";

    return 0;
}
