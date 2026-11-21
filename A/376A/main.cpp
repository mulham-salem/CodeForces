#include <bits/stdc++.h>
using namespace std;

int main() {

    string s;
    cin >> s;

    int pivot = s.find('^');

    long long left = 0;
    long long right = 0;

    for (int i = 0; i < s.size(); i++) {

        if (isdigit(s[i])) {

            int weight = s[i] - '0';

            if (i < pivot) {

                int distance = pivot - i;
                left += weight * distance;

            }
            else if (i > pivot) {

                int distance = i - pivot;
                right += weight * distance;

            }
        }
    }

    if (left > right)
        cout << "left";

    else if (right > left)
        cout << "right";

    else
        cout << "balance";

    return 0;
}
