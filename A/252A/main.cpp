#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    for (int &x : a) {
        cin >> x;
    }

    int answer = 0;

    for (int left = 0; left < n; left++) {
        int currentXor = 0;

        for (int right = left; right < n; right++) {
            currentXor ^= a[right];
            answer = max(answer, currentXor);
        }
    }

    cout << answer << '\n';

    return 0;
}
