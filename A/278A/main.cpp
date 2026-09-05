#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int d[100];
    int totalDistance = 0;

    for (int i = 0; i < n; i++) {
        cin >> d[i];
        totalDistance += d[i];
    }

    int s, t;
    cin >> s >> t;

    if (s > t)
        swap(s, t);

    int distance1 = 0;

    for (int i = s - 1; i < t - 1; i++) {
        distance1 += d[i];
    }

    int distance2 = totalDistance - distance1;

    cout << min(distance1, distance2) << endl;

    return 0;
}
