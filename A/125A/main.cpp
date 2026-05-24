#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Convert cm to inches with rounding
    int inches = (n + 1) / 3;

    // Convert inches to feet and remaining inches
    int feet = inches / 12;
    int rem = inches % 12;

    cout << feet << " " << rem;

    return 0;
}
