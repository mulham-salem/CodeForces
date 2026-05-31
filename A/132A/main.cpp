#include <iostream>
#include <string>
using namespace std;

int reverseBits(int x) {
    int res = 0;

    for (int i = 0; i < 8; i++) {
        res <<= 1;
        res |= (x & 1);
        x >>= 1;
    }

    return res;
}

int main() {
    string text;
    getline(cin, text);

    int prev = 0;

    for (char c : text) {
        int cur = reverseBits((int)c);

        int value = (prev - cur + 256) % 256;

        cout << value << '\n';

        prev = cur;
    }

    return 0;
}
