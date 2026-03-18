#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int current = 1;

    for (int i = 1; i < n; i++) {
        current = (current + i - 1) % n + 1;
        cout << current << " ";
    }

    return 0;
}
