#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int i = 1;

    while (true) {
        if (m < i) {
            break;
        }

        m -= i;
        i++;

        if (i > n) {
            i = 1;
        }
    }

    cout << m << endl;

    return 0;
}
