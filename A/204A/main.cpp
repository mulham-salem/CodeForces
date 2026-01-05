#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    long long n;
    cin >> n;

    long long a[n], minTown = INT_MAX;
    int pos = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < minTown) {
            minTown = a[i];
            pos = i;
        }
    }

    int repeat = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == minTown)
            repeat++;
    }

    if (repeat > 1)
        cout << "Still Rozdil";
    else
        cout << pos+1;
    return 0;
}
