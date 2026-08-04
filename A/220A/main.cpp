#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    b = a;
    sort(b.begin(), b.end());

    int diff = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i])
            diff++;
    }

    if (diff <= 2)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}
