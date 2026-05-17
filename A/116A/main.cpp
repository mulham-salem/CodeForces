#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int current = 0;
    int capacity = 0;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        current -= a;   // passengers leave
        current += b;   // passengers enter

        capacity = max(capacity, current);
    }

    cout << capacity << endl;

    return 0;
}
