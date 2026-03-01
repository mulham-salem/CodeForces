#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> primeCount(n + 1, 0);

    for (int i = 2; i <= n; i++) {
        if (primeCount[i] == 0) {
            for (int j = i; j <= n; j += i) {
                primeCount[j]++;
            }
        }
    }

    int answer = 0;

    for (int i = 1; i <= n; i++) {
        if (primeCount[i] == 2)
            answer++;
    }

    cout << answer;

    return 0;
}
