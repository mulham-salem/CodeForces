#include <iostream>
#include <string>
using namespace std;

bool valid(const string &s) {
    if (s.empty()) return false;
    if (s.size() > 1 && s[0] == '0') return false;

    long long num = 0;
    for (char c : s) {
        num = num * 10 + (c - '0');
        if (num > 1000000) return false;
    }
    return true;
}

long long toNumber(const string &s) {
    long long num = 0;
    for (char c : s)
        num = num * 10 + (c - '0');
    return num;
}

int main() {
    string s;
    cin >> s;

    long long ans = -1;
    int n = s.size();

    for (int i = 1; i <= n - 2; i++) {
        for (int j = i + 1; j <= n - 1; j++) {
            string a = s.substr(0, i);
            string b = s.substr(i, j - i);
            string c = s.substr(j);

            if (valid(a) && valid(b) && valid(c)) {
                long long sum = toNumber(a) + toNumber(b) + toNumber(c);
                if (sum > ans)
                    ans = sum;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
