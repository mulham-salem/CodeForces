#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;

int Find(int x) {
    if (parent[x] == x)
        return x;

    return parent[x] = Find(parent[x]);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> ans(n + 1, 0);

    parent.resize(n + 2);

    for (int i = 1; i <= n + 1; i++) {
        parent[i] = i;
    }

    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;

        int i = Find(l);

        while (i <= r) {

            if (i == x) {
                i = Find(i + 1);
            }
            else {
                ans[i] = x;

                parent[i] = Find(i + 1);

                i = Find(i);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}
