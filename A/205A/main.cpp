#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long minTime = LLONG_MAX;
    int cityIndex = -1;
    int countMin = 0;

    for (int i = 1; i <= n; i++) {
        long long time;
        cin >> time;

        if (time < minTime) {
            minTime = time;
            cityIndex = i;
            countMin = 1;
        } else if (time == minTime) {
            countMin++;
        }
    }

    if (countMin == 1)
        cout << cityIndex;
    else
        cout << "Still Rozdil";

    return 0;
}
