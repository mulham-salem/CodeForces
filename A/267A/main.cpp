#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        long long a, b;
        cin >> a >> b;

        long long operations = 0;

        while (a > 0 && b > 0) {
            if (a >= b) {
                operations += a / b;
                a %= b;
            } else {
                operations += b / a;
                b %= a;
            }
        }

        cout << operations << endl;
    }

    return 0;
}
