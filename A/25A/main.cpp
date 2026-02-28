#include <iostream>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[n];

    int even_count = 0, odd_count = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] % 2 == 0) {
            even_count++;
        }
        else {
            odd_count++;
        }
    }

    bool even_majority = false;

    if (even_count > odd_count)
        even_majority = true;

    for (int i = 0; i < n; i++) {
        if (even_majority && arr[i] % 2 != 0) {
            cout << i + 1 << endl;
            break;
        }
        else if (!even_majority && arr[i] % 2 == 0) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}
