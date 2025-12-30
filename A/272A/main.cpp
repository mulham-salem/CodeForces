#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int fingers, sumOfFingers = 0;
    for (int i = 0; i < n ;i++) {
        cin >> fingers;
        sumOfFingers += fingers;
    }

    int notDimaTurn = 0;
    for (int i = 1; i <= 5; i++) {
        int totalFingers = sumOfFingers + i;
        if ( totalFingers % (n + 1) != 1 ) {
            notDimaTurn++;
        }
    }

    cout << notDimaTurn;

    return 0;
}
