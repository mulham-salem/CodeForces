#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    string names[5] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

    long long groupSize = 1;

    while (n > 5 * groupSize) {
        n -= 5 * groupSize;
        groupSize *= 2;
    }

    long long index = (n - 1) / groupSize;

    cout << names[index] << endl;

    return 0;
}
