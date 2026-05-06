#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long a[100];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (a[i] - 1) * (i + 1) + 1;
    }

    cout << ans << endl;

    return 0;
}
