#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string s;
    double p;
    cin >> s >> p;

    int ones = 0, questions = 0;

    for (char c : s) {
        if (c == '1') {
            ones++;
        } else if (c == '?') {
            questions++;
        }
    }

    double expectedBadDays = ones + questions * p;
    double answer = expectedBadDays / s.size();

    cout << fixed << setprecision(5) << answer << endl;

    return 0;
}
