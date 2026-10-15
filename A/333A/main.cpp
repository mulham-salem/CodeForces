#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    long long power = 1;

    while (n % power == 0) {
        power *= 3;
    }

    long long answer = n / power;

    if (n % power != 0) {
        answer++;
    }

    cout << answer << endl;

    return 0;
}
