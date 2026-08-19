#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    vector<int> folders;

    int currentSize = 0;
    int negativeCount = 0;

    for (int x : a) {
        if (x < 0)
            negativeCount++;

        if (negativeCount > 2) {
            folders.push_back(currentSize);

            currentSize = 1;
            negativeCount = 1;
        } else {
            currentSize++;
        }
    }

    folders.push_back(currentSize);

    cout << folders.size() << '\n';

    for (int size : folders)
        cout << size << ' ';

    cout << '\n';

    return 0;
}
