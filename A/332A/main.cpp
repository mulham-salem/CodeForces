#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int answer = 0;

    for (int i = n; i < s.size(); i += n) {
        if (s[i - 1] == s[i - 2] &&
            s[i - 2] == s[i - 3]) {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}
