#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int cntA = 0, cntB = 0;
    for (char c : a) if (c == '1') cntA++;
    for (char c : b) if (c == '1') cntB++;

    if (cntA % 2 == 1) cntA++;

    if (cntB <= cntA) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
