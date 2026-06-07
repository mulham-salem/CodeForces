#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    int c47 = 0, c74 = 0;

    for (size_t i = 0; i < a.size(); i++) {
        if (a[i] == '4' && b[i] == '7')
            c47++;
        else if (a[i] == '7' && b[i] == '4')
            c74++;
    }

    cout << max(c47, c74) << '\n';

    return 0;
}
