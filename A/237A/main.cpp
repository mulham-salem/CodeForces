#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector <pair<int, int>> time;

    for (int i = 0; i < n; i++)
    {
        int h, m;
        cin >> h >> m;

        time.push_back({h, m});
    }

    map<pair<int, int>, int> freqNum;

    for (auto &t : time)
        freqNum[t]++;


    int maxCashes = 1;

    for (auto &m : freqNum)
        maxCashes = max(maxCashes, m.second);

    cout << maxCashes;
    return 0;
}
