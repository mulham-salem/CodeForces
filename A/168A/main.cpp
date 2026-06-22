#include <iostream>
using namespace std;

int main() {
    long long n, x, y;
    cin >> n >> x >> y;

    long long required = (n * y + 99) / 100; // ceil(n * y / 100)

    cout << max(0LL, required - x) << '\n';

    return 0;
}
