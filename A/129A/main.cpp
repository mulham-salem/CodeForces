#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int total = 0;
    int oddCount = 0, evenCount = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        total += x;

        if (x % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    if (total % 2 == 0)
        cout << evenCount;
    else
        cout << oddCount;

    return 0;
}
