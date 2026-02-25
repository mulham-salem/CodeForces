#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);

    int first_min = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > first_min) {
            cout << arr[i];
            return 0;
        }
    }

    cout << "NO";
    return 0;
}
