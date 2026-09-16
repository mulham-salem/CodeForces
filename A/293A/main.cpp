#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    int both = 0;
    int firstOnly = 0;
    int secondOnly = 0;
    int none = 0;

    for (int i = 0; i < 2 * n; i++) {
        if (s[i] == '1' && t[i] == '1')
            both++;
        else if (s[i] == '1')
            firstOnly++;
        else if (t[i] == '1')
            secondOnly++;
        else
            none++;
    }

    int first = 0;
    int second = 0;

    for (int turn = 0; turn < 2 * n; turn++) {

        if (turn % 2 == 0) {
            // First's turn

            if (both > 0) {
                both--;
                first++;
            }
            else if (firstOnly > 0) {
                firstOnly--;
                first++;
            }
            else if (secondOnly > 0) {
                secondOnly--;
            }
            else {
                none--;
            }
        }
        else {
            // Second's turn

            if (both > 0) {
                both--;
                second++;
            }
            else if (secondOnly > 0) {
                secondOnly--;
                second++;
            }
            else if (firstOnly > 0) {
                firstOnly--;
            }
            else {
                none--;
            }
        }
    }

    if (first > second)
        cout << "First\n";
    else if (second > first)
        cout << "Second\n";
    else
        cout << "Draw\n";

    return 0;
}
