#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    // Check impossible cases
    if (k > n) {
        cout << -1 << endl;
        return 0;
    }

    if (k == 1 && n > 1) {
        cout << -1 << endl;
        return 0;
    }

    string result = "";

    if (k == 1) {
        // n must be 1 here
        result = "a";
    } else {
        // First n-k+2 characters alternate between 'a' and 'b'
        int altLength = n - k + 2;
        for (int i = 0; i < altLength; i++) {
            if (i % 2 == 0) {
                result += 'a';
            } else {
                result += 'b';
            }
        }

        // Then add characters 'c', 'd', ... for the remaining k-2 positions
        for (int i = 0; i < k - 2; i++) {
            result += char('c' + i);
        }
    }

    cout << result << endl;

    return 0;
}
