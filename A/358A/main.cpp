#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    for (int i = 0; i < n - 1; i++) {

        int a = min(x[i], x[i + 1]);
        int b = max(x[i], x[i + 1]);

        for (int j = i + 2; j < n - 1; j++) {

            int c = min(x[j], x[j + 1]);
            int d = max(x[j], x[j + 1]);

            if ((a < c && c < b && b < d) ||
                (c < a && a < d && d < b)) {

                cout << "yes";
                return 0;
            }
        }
    }

    cout << "no";

    return 0;
}
