#include <iostream>
#include <bits/stdc++.h>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    if (num <= 1) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> p;

    for (int num = 2; num <= n; num++) {
        bool primeFlag  = true;

        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                primeFlag = false;
                break;
            }
        }

        if (primeFlag) {
            p.push_back(num);
        }
    }

    int ans = 0;

    for (int i = 0; i < p.size()-1; i++) {
        int candidate = p[i] + p[i+1] + 1;
        if (candidate <= n && isPrime(candidate)) {
            ans++;
        }
    }

    if (ans >= k)
        cout << "YES";

    else
        cout << "NO";

    return 0;
}
