#include <iostream>
using namespace std;

bool valid(int g, int b) {
    return (b >= g - 1) && (b <= 2 * (g + 1));
}

int main() {
    int al, ar, bl, br;
    cin >> al >> ar;
    cin >> bl >> br;

    if (valid(al, br) || valid(ar, bl))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
