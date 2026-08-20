#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    long long d;

    cin >> n >> d;

    vector<long long> x(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    long long answer = 0;
    int right = 0;

    for (int left = 0; left < n; left++) {

        while (right < n && x[right] - x[left] <= d) {
            right++;
        }

        long long count = right - left;

        if (count >= 3) {
            answer += (count - 1) * (count - 2) / 2;
        }
    }

    cout << answer << '\n';

    return 0;
}
