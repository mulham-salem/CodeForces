#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i != j && i != k && j != k) {
                    if (a[i] == a[j] + a[k]) {
                        cout << i << " " << j << " " << k;
                        return 0;
                    }
                }
            }
        }
    }

    cout << -1;

    return 0;
}
