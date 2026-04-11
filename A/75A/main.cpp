#include <iostream>
#include <string>
using namespace std;

// function to remove zeros and convert back to integer
int removeZeros(int x) {
    string s = to_string(x);
    string result = "";

    for (char c : s) {
        if (c != '0') {
            result += c;
        }
    }

    // if all digits were zeros → return 0
    if (result.empty()) return 0;

    return stoi(result);
}

int main() {
    int a, b;
    cin >> a >> b;

    int c = a + b;

    int a2 = removeZeros(a);
    int b2 = removeZeros(b);
    int c2 = removeZeros(c);

    if (a2 + b2 == c2)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
