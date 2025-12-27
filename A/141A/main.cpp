#include <bits/stdc++.h>
using namespace std;


int main() {
    string guest, host, pile;
    cin >> guest >> host >> pile;

    string a = guest + host;
    sort(a.begin(), a.end());
    sort(pile.begin(), pile.end());

    if ( a == pile ) cout << "YES";
    else cout << "NO";
    return 0;
}
