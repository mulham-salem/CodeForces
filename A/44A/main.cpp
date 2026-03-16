#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<string, string>> leaves;

    for (int i = 0; i < n; i++) {
        string tree, color;
        cin >> tree >> color;
        leaves.insert({tree, color});
    }

    cout << leaves.size() << endl;
    return 0;
}
