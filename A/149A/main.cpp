#include <iostream>
#include<algorithm>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int k;
    cin >> k;


    int a[12];
    for (int i = 0; i < 12; i++)
        cin >> a[i];

    if ( k == 0 ) {
        cout << 0;
        return 0;
    }

    sort(a, a + 12, greater<int>());
    int month = 0, countOfMonth = 0;

    for (int i = 0; i < 12; i++) {
        if (month < k) {
            month += a[i];
            countOfMonth++;
        }
    }

    if (month < k) {
        cout << -1;
        return 0;
    } 
	else {
        cout << countOfMonth;
    }

    return 0;
}
