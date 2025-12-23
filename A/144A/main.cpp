#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int max_index = max_element(a.begin(), a.end()) - a.begin();

    int min_value = *min_element(a.begin(), a.end());
    int min_index;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == min_value) {
            min_index = i;
            break;
        }
    }

    int moves = max_index + (n - 1 - min_index);

    if (max_index > min_index)
        moves--;

    cout << moves;

    return 0;
}
