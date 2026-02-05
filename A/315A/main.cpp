#include <bits/stdc++.h>
#include <map>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    map<int,int> cnt;
    for (int i = 0; i < n; i++) cnt[b[i]]++;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt[a[i]] == 0) ans++;
        else if (cnt[a[i]] == 1 && a[i] == b[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}
