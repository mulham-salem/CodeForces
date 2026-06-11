#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> grades(n);
    for (int i = 0; i < n; i++) {
        cin >> grades[i];
    }

    vector<bool> successful(n, false);

    for (int subject = 0; subject < m; subject++) {
        char bestMark = '0';

        for (int student = 0; student < n; student++) {
            bestMark = max(bestMark, grades[student][subject]);
        }

        for (int student = 0; student < n; student++) {
            if (grades[student][subject] == bestMark) {
                successful[student] = true;
            }
        }
    }

    int answer = 0;
    for (bool s : successful) {
        if (s) answer++;
    }

    cout << answer << '\n';
    return 0;
}
