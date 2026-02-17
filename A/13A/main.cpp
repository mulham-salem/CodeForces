#include <bits/stdc++.h>
#include <numeric>

using namespace std;

int sum_of_digits_in_base(int A, int b) {
    int sum = 0;
    while (A > 0) {
        sum += A % b;
        A /= b;
    }
    return sum;
}

int main() {
    int A;
    cin >> A;

    int total_sum = 0;

    for (int base = 2; base <= A - 1; base++) {
        total_sum += sum_of_digits_in_base(A, base);
    }

    int denominator = A - 2;

    int g = __gcd(total_sum, denominator);

    cout << total_sum / g << "/" << denominator / g << endl;

    return 0;
}
