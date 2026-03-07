#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long d;
    cin >> d;

    vector<long long> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    long long count_pair = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {

            long long diff = a[j] - a[i];

            if (diff <= d)
                count_pair += 2;
        }
    }

    cout << count_pair;

    return 0;
}
