#include <iostream>

using namespace std;

int main() {

    string path;
    cin >> path;

    string result = "";

    for (char c : path) {
        if (c == '/') {
            if (result.empty() || result.back() != '/')
                result += '/';
        }
        else {
            result += c;
        }
    }

    if (result.size() > 1 && result.back() == '/')
        result.pop_back();

    cout << result;

    return 0;
}
