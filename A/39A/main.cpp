#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    long long a;
    string s;
    cin >> a >> s;

    vector<pair<long long,int>> v;

    for (int i = 0; i < s.size();) {
        int sign = 1;
        if (s[i] == '+') { sign = 1; i++; }
        else if (s[i] == '-') { sign = -1; i++; }

        long long k = 0;
        bool has = false;
        while (i < s.size() && isdigit(s[i])) {
            k = k*10 + (s[i]-'0');
            i++;
            has = true;
        }
        if (!has) k = 1;

        if (i < s.size() && s[i] == '*') i++;

        int shift;
        if (s.substr(i,3) == "a++") {
            shift = 0;
            i += 3;
        } else {
            shift = 1;
            i += 3;
        }

        v.push_back({sign*k, shift});
    }

    sort(v.begin(), v.end());

    long long ans = 0;

    for (auto [k, sh] : v) {
        if (sh == 0) {
            ans += k * a;
            a++;
        } else {
            a++;
            ans += k * a;
        }
    }

    cout << ans;

    return 0;
}
