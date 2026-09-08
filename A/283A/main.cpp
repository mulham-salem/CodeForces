#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n;
long long add[MAXN];       // add[i] = value to add to all elements in prefix up to i
long long val[MAXN];       // actual value of element at position i
long long sum = 0;         // total sum of the sequence
int sz = 1;                // current size of sequence

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    // initialize sequence with 0
    val[1] = 0;
    add[1] = 0;
    sum = 0;
    sz = 1;

    cout << fixed << setprecision(6);

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, x;
            cin >> a >> x;

            // add x to first a elements
            add[a] += x;
            sum += 1LL * a * x;

        } else if (t == 2) {
            int k;
            cin >> k;

            // append k to end
            sz++;
            val[sz] = k;
            add[sz] = 0;
            sum += k;

        } else { // t == 3
            // remove last element
            // first, propagate add[sz] to val[sz] before removing
            val[sz] += add[sz];

            // remove its contribution from sum
            sum -= val[sz];

            // propagate add[sz-1] to add[sz]? Actually we need to handle propagation
            // When we remove, the add[sz] is no longer needed, but add[sz-1] might need to include it
            // Actually we need to carry add[sz] to add[sz-1] because the removal affects the prefix
            add[sz-1] += add[sz];

            sz--;
        }

        // output average
        cout << (double)sum / sz << "\n";
    }

    return 0;
}
