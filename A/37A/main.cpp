#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> tower(n);

    for (int i = 0; i < n; i++) {
        cin >> tower[i];
    }

    vector<int> freq(1001, 0);

    for (auto t : tower) {
        freq[t]++;
    }

    int maxFreq = 0;
    int towers = 0;

    for (int i = 0; i <= 1000; i++) {
        if (freq[i] > 0) {
            towers++;
            maxFreq = max(maxFreq, freq[i]);
        }
    }

    cout << maxFreq << " " << towers;

    return 0;
}
