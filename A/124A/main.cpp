#include <iostream>
#include<algorithm>
#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int minFront = max(a, n - b - 1);
    int pos = n - minFront;
    cout << pos;
    return 0;
}
