#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

bool check(string s, string a1, string a2)
{
    size_t pos1 = s.find(a1);
    if (pos1 == string::npos) return false;

    size_t pos2 = s.find(a2, pos1 + a1.length());
    if (pos2 == string::npos) return false;

    return true;
}

int main()
{
    string s, a1, a2;
    cin >> s >> a1 >> a2;

    bool isForward = check(s, a1, a2);

    string r = s;
    reverse(r.begin(), r.end());
    bool isBackward = check(r, a1, a2);

    if (isForward && isBackward) cout << "both";
    else if (isForward) cout << "forward";
    else if (isBackward) cout << "backward";
    else cout << "fantasy";

    return 0;
}
