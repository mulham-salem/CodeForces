#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n ; i++)
        cin >> a[i];

    int m;
    cin >> m;

    int b[m];
    for (int j = 0; j < m ; j++)
        cin >> b[j];

    int maxRatio = 0, ratio = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (b[j] % a[i] == 0)
            {
                ratio = b[j] / a[i];
                if (ratio > maxRatio) {
                    maxRatio = ratio;
                    count = 1;
                }
                else if (ratio == maxRatio)
                    count++;
            }
        }
    }

    cout << count;
    return 0;
}
