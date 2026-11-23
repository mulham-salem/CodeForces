#include <bits/stdc++.h>
using namespace std;

const int LIMIT = 100000;

struct Operation {
    int type;
    long long len;
    long long prevLen;
    long long x;
};

int main() {

    int m;
    cin >> m;

    vector<Operation> ops;
    vector<int> a;

    long long currentLength = 0;

    for (int i = 0; i < m; i++) {

        int type;
        cin >> type;

        if (type == 1) {

            long long x;
            cin >> x;

            long long oldLength = currentLength;

            currentLength++;

            ops.push_back({1, currentLength, oldLength, x});

            if (a.size() < LIMIT) {
                a.push_back(x);
            }

        }
        else {

            long long l, c;
            cin >> l >> c;

            long long oldLength = currentLength;

            currentLength += l * c;

            ops.push_back({2, currentLength, oldLength, l});

            long long added = min(
                l * c,
                (long long)LIMIT - (long long)a.size()
            );

            for (long long j = 0; j < added; j++) {
                a.push_back(a[j % l]);
            }
        }
    }

    int n;
    cin >> n;

    while (n--) {

        long long position;
        cin >> position;

        if (position <= (long long)a.size()) {

            cout << a[position - 1] << " ";
            continue;

        }

        int left = 0;
        int right = m - 1;

        while (left < right) {

            int mid = (left + right) / 2;

            if (ops[mid].len >= position) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }

        if (ops[left].type == 1) {

            cout << ops[left].x << " ";

        }
        else {

            long long l = ops[left].x;
            long long prevLen = ops[left].prevLen;

            position = (position - prevLen - 1) % l + 1;

            cout << a[position - 1] << " ";

        }
    }

    cout << '\n';

    return 0;
}
