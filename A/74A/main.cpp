#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int bestScore = INT_MIN;
    string bestName = "";

    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;

        int plus, minus, a, b, c, d, e;
        cin >> plus >> minus >> a >> b >> c >> d >> e;

        int total = a + b + c + d + e + (plus * 100) - (minus * 50);

        if (total > bestScore) {
            bestScore = total;
            bestName = name;
        }
    }

    cout << bestName << "\n";
    return 0;
}
