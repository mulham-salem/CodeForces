#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    string door;
    int rail;

    cin >> door >> rail;

    if ((door == "front" && rail == 1) ||
        (door == "back" && rail == 2))
    {
        cout << 'L';
    }
    else {
        cout << 'R';
    }

    return 0;
}
