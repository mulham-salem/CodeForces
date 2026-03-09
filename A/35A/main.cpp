#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int ball;
    cin >> ball;

    for (int i = 0; i < 3; i++) {
        int a, b;
        cin >> a >> b;

        if (ball == a)
            ball = b;
        else if (ball == b)
            ball = a;
    }

    cout << ball << endl;

    return 0;
}
