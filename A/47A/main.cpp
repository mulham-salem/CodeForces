#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 0;

    for (int i = 1; i <= n; i++) {
        sum += i;
        if (sum == n) {
            cout << "YES";
            return 0;
        }
        if (sum > n) break;
    }

    cout << "NO";

    return 0;
}
