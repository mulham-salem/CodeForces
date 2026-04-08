#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;
    for (int d = 3; d * d <= num; d += 2) {
        if (num % d == 0) return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n)) {
        cout << n << "=" << n << endl;
        return 0;
    }

    vector<int> primes;
    for (int i = n; i >= 2; i--) {
        if (isPrime(i)) {
            primes.push_back(i);
        }
    }
    primes.push_back(1);

    vector<int> best;
    int remaining = n;

    for (int p : primes) {
        while (remaining >= p) {
            best.push_back(p);
            remaining -= p;
        }
    }

    if (remaining == 0) {
        for (int i = 0; i < best.size(); i++) {
            if (i > 0) cout << "+";
            cout << best[i];
        }
        cout << "=" << n << endl;
    } else {
        cout << 0 << endl;
    }

    return 0;
}
