#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int C;
    cin >> C;

    vector<bool> isHoliday(N + 1, false);

    for (int i = 0; i < C; i++) {
        int x;
        cin >> x;
        isHoliday[x] = true;
    }

    int last = 0, presents = 0;

    for (int i = 1; i <= N; i++) {
        if (isHoliday[i] || i - last == K) {
            presents++;
            last = i;
        }
    }

    cout << presents;

    return 0;
}
