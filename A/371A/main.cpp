#include <bits/stdc++.h>
using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int answer = 0;

    for (int i = 0; i < k; i++) {

        int count1 = 0;
        int count2 = 0;

        for (int j = i; j < n; j += k) {

            if (a[j] == 1) {
                count1++;
            }
            else {
                count2++;
            }
        }

        answer += min(count1, count2);
    }

    cout << answer << endl;

    return 0;
}
