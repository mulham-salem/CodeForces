#include <iostream>
using namespace std;

bool canFit(string n,  string maxValue) {
    if (n.length() < maxValue.length())
        return true;
    else if (n.length() > maxValue.length())
        return false;
    return n <= maxValue;
}

int main() {
    string byteMax  = "127";
    string shortMax = "32767";
    string intMax   = "2147483647";
    string longMax  = "9223372036854775807";

    string n;
    cin >> n;

    if (canFit(n, byteMax)) cout << "byte";
    else if (canFit(n, shortMax)) cout << "short";
    else if (canFit(n, intMax)) cout << "int";
    else if (canFit(n, longMax)) cout << "long";
    else cout << "BigInteger";

    return 0;
}
