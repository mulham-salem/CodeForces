#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    string c;
    cin >> c;

    vector<int> index;

    for (int i = 0; i < n; i++) {
        if (c[i] == '1')
            index.push_back(i);
    }

    int diff = index[1] - index[0];

    int s = index.size();

    for (int i = 0; i < s-1; i++) {
        int temp = index[i+1] - index[i];
        if (temp != diff) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    return 0;
}
