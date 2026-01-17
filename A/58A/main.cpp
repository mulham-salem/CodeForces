#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

int main() {
    string s;
    cin >> s;

    string target = "hello";
    int index = 0;

    for (char c : s) {
        if (c == target[index])
            index++;

        if (index == target.length())
            break;
    }

    if (index == target.length())
        cout << "YES";
    else
        cout << "NO";


    return 0;
}
