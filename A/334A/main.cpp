#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int left = 1;
    int right = n * n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n / 2; j++) {
            cout << left << " " << right << " ";

            left++;
            right--;
        }

        cout << endl;
    }

    return 0;
}
