#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();

    int L = 1, R = n;

    for (int i = 0; i < m; i++) {
        string s;
        getline(cin, s);

        int pos = stoi(s.substr(s.find_last_of(' ') + 1));

        if (s.find("left") != string::npos) {
            R = min(R, pos - 1);
        } else {
            L = max(L, pos + 1);
        }
    }

    if (L > R)
        cout << -1 << endl;
    else
        cout << (R - L + 1) << endl;

    return 0;
}
