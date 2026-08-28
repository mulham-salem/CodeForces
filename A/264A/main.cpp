#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> right, left;

    for (int i = 0; i < s.size(); i++) {
        int stone = i + 1;

        if (s[i] == 'r')
            right.push_back(stone);
        else
            left.push_back(stone);
    }

    for (int x : right)
        cout << x << '\n';

    for (int i = left.size() - 1; i >= 0; i--)
        cout << left[i] << '\n';

    return 0;
}
