#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int t;
    int counterT[4] = {0};
    int matrixChildT[4][5001];

    for(int i=1; i<=n; i++)
    {
        cin >> t;

        counterT[t]++;

        matrixChildT[t][counterT[t]] = i;
    }

    int w;
    w = min(counterT[1], min(counterT[2], counterT[3]));
    cout << w << endl;

    for(int i=1; i<=w; i++)
    {
        cout << matrixChildT[1][i] << " "
             << matrixChildT[2][i] << " "
             << matrixChildT[3][i] << " "
             << endl;
    }
    return 0;
}