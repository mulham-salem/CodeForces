#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> triangular;

    for (long long k = 1;; k++) {
        long long t = k * (k + 1) / 2;
        if (t > n) break;
        triangular.push_back(t);
    }

    int left = 0;
    int right = triangular.size() - 1;

    while (left <= right) {
        long long sum = triangular[left] + triangular[right];

        if (sum == n) {
            cout << "YES";
            return 0;
        }

        if (sum < n)
            left++;
        else
            right--;
    }

    cout << "NO";

    return 0;
}
