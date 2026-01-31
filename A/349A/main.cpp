#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt25 = 0, cnt50 = 0;
    bool failed = false;

    for (int i = 0; i < n; i++) {
        int coin;
        cin >> coin;

        if (coin == 25)
            cnt25++;

        else if (coin == 50) {
            if (cnt25 >= 1) {
                cnt25--;
                cnt50++;
            }
            else
                failed = true;
        }

        else if (coin == 100) {
            if (cnt25 > 0 && cnt50 > 0) {
               cnt50--;
               cnt25--;
            }
            else if (cnt25 >= 3)
                cnt25 -= 3;

            else
                failed = true;
        }
    }

    if (failed)
        cout << "NO";
    else
        cout << "YES";

    return 0;
}
