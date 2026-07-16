#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int need = 5 * n - k;
    need -= min(need, 2 * n);

    cout << need << '\n';

    return 0;
}
