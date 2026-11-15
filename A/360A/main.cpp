#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9;

struct Operation {
    int type, l, r;
    long long value;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Operation> ops(m);

    vector<long long> ans(n, INF);
    vector<long long> add(n, 0);

    // Phase 1: Construct the initial array

    for (int i = 0; i < m; i++) {

        cin >> ops[i].type
            >> ops[i].l
            >> ops[i].r
            >> ops[i].value;

        int l = ops[i].l - 1;
        int r = ops[i].r - 1;

        if (ops[i].type == 1) {

            for (int j = l; j <= r; j++) {
                add[j] += ops[i].value;
            }

        }
        else {

            for (int j = l; j <= r; j++) {
                ans[j] = min(ans[j],
                             ops[i].value - add[j]);
            }

        }
    }

    // Phase 2: Validate the constructed array

    vector<long long> current = ans;

    for (int i = 0; i < m; i++) {

        int l = ops[i].l - 1;
        int r = ops[i].r - 1;

        if (ops[i].type == 1) {

            for (int j = l; j <= r; j++) {
                current[j] += ops[i].value;
            }

        }
        else {

            long long mx = current[l];

            for (int j = l; j <= r; j++) {
                mx = max(mx, current[j]);
            }

            if (mx != ops[i].value) {
                cout << "NO\n";
                return 0;
            }

        }
    }

    cout << "YES\n";

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

    cout << "\n";

    return 0;
}
