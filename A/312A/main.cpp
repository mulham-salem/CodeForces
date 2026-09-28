#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();

    while (n--) {
        string s;
        getline(cin, s);

        bool starts = s.rfind("miao.", 0) == 0;
        bool ends = s.size() >= 5 &&
                    s.substr(s.size() - 5) == "lala.";

        if (starts && !ends)
            cout << "Rainbow's\n";
        else if (!starts && ends)
            cout << "Freda's\n";
        else
            cout << "OMG>.< I don't know!\n";
    }

    return 0;
}
