#include <iostream>
#include <string>
using namespace std;

int getRank(char c) {
    string ranks = "6789TJQKA";
    return ranks.find(c);
}

int main() {
    char trump;
    cin >> trump;

    string a, b;
    cin >> a >> b;

    char rank1 = a[0];
    char suit1 = a[1];

    char rank2 = b[0];
    char suit2 = b[1];

    if (suit1 == trump && suit2 != trump) {
        cout << "YES";
    }

    else if (suit1 == suit2 && getRank(rank1) > getRank(rank2)) {
        cout << "YES";
    }

    else {
        cout << "NO";
    }

    return 0;
}
