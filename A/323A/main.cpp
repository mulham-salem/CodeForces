#include <iostream>
using namespace std;

int main() {
    int k;
    cin >> k;

    if (k % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            for (int z = 0; z < k; z++) {
                if ((j / 2 + z / 2 + i) % 2 == 0)
                    cout << 'b';
                else
                    cout << 'w';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
