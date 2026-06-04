#include <bits/stdc++.h>
using namespace std;

bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

string rhymePart(const string &s, int k) {
    int cnt = 0;

    for (int i = (int)s.size() - 1; i >= 0; --i) {
        if (isVowel(s[i])) {
            ++cnt;
            if (cnt == k)
                return s.substr(i);
        }
    }

    return "";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    bool canAABB = true;
    bool canABAB = true;
    bool canABBA = true;
    bool allAAAA = true;

    for (int q = 0; q < n; q++) {
        string r[4];

        for (int i = 0; i < 4; i++) {
            string s;
            cin >> s;
            r[i] = rhymePart(s, k);
        }

        bool valid = true;
        for (int i = 0; i < 4; i++) {
            if (r[i].empty()) {
                valid = false;
                break;
            }
        }

        bool aabb = false, abab = false, abba = false, aaaa = false;

        if (valid) {
            aabb = (r[0] == r[1] && r[2] == r[3]);
            abab = (r[0] == r[2] && r[1] == r[3]);
            abba = (r[0] == r[3] && r[1] == r[2]);
            aaaa = (r[0] == r[1] && r[1] == r[2] && r[2] == r[3]);
        }

        if (!(aabb || abab || abba)) {
            cout << "NO\n";
            return 0;
        }

        canAABB &= aabb;
        canABAB &= abab;
        canABBA &= abba;
        allAAAA &= aaaa;
    }

    if (allAAAA)
        cout << "aaaa\n";
    else if (canAABB)
        cout << "aabb\n";
    else if (canABAB)
        cout << "abab\n";
    else if (canABBA)
        cout << "abba\n";
    else
        cout << "NO\n";

    return 0;
}
