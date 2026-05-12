#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    int count4 = -1, count7 = -1;

    // Try all possible counts of digit 7
    for (int sevens = 0; sevens * 7 <= n; sevens++) {
        int remaining = n - sevens * 7;

        if (remaining % 4 == 0) {
            int fours = remaining / 4;

            // Choose the solution with minimum total digits
            if (count4 == -1 || fours + sevens < count4 + count7) {
                count4 = fours;
                count7 = sevens;
            }
        }
    }

    if (count4 == -1) {
        cout << -1 << endl;
        return 0;
    }

    // Print smallest number:
    // all 4's first, then 7's
    for (int i = 0; i < count4; i++)
        cout << 4;

    for (int i = 0; i < count7; i++)
        cout << 7;

    cout << endl;

    return 0;
}
