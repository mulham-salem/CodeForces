#include <bits/stdc++.h>
using namespace std;

int main() {

    string s, t;
    cin >> s >> t;

    int currentHours = stoi(s.substr(0, 2));
    int currentMinutes = stoi(s.substr(3, 2));

    int sleepHours = stoi(t.substr(0, 2));
    int sleepMinutes = stoi(t.substr(3, 2));

    int currentTime = currentHours * 60 + currentMinutes;

    int sleepTime = sleepHours * 60 + sleepMinutes;

    int result = currentTime - sleepTime;

    if (result < 0) {
        result += 1440;
    }

    int hours = result / 60;
    int minutes = result % 60;

    cout << setfill('0') << setw(2) << hours
         << ":"
         << setw(2) << minutes << endl;

    return 0;
}
