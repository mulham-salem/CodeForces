#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> candies(n, 1);

    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'R')
            candies[i+1] = candies[i] + 1;

        else if (s[i] == '=')
            candies[i+1] = candies[i];
    }

    for (int i = n-2; i >= 0; i--) {
        if (s[i] == 'L')
            candies[i] = max(candies[i], candies[i+1] + 1);

        else if (s[i] == '=')
            candies[i] = max(candies[i], candies[i+1]);
    }

    for (auto c : candies) {
        cout << c << " ";
    }

    return 0;
}
