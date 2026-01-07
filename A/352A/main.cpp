#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int countOfZero = 0, countOfFive = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if ( a == 0 ) countOfZero++;
        else countOfFive++;
    }

    if ( countOfZero == 0 ) {
        cout << -1;
        return 0;
    }

    if ( countOfFive >= 9 ) {
        while ( countOfFive % 9 != 0 )
            countOfFive--;
    } else {
        cout << 0;
        return 0;
    }

    while ( countOfFive-- )
        cout << 5;

    while ( countOfZero-- )
        cout << 0;

    return 0;
}
