#include <bits/stdc++.h>
#include <vector>
#include <map>

using namespace std;

int main()
{
    string s, t;
    cin >> s >> t;

    int x1 = s[0] - 'a';
    int y1 = s[1] - '0';

    int x2 = t[0] - 'a';
    int y2 = t[1] - '0';

    vector<string> moves;

    while (x1 != x2 || y1 != y2)
    {
        string currentMove = "";

        // horizontal movement
        if (x1 < x2) {
            currentMove += "R";
            x1 = x1 + 1;
        } else if (x1 > x2) {
            currentMove += "L";
            x1 = x1 - 1;
        }

        // vertical movement
        if (y1 < y2) {
            currentMove += "U";
            y1 = y1 + 1;
        } else if (y1 > y2) {
            currentMove += "D";
            y1 = y1 - 1;
        }

        moves.push_back(currentMove);
    }

    cout << moves.size() << "\n";

    for (auto m : moves)
        cout << m << "\n";

    return 0;
}
