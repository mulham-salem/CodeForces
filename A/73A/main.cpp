#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x, y, z, k;
    cin >> x >> y >> z >> k;

    vector<long long> d = {x, y, z};
    sort(d.begin(), d.end()); // d[0]<=d[1]<=d[2]

    long long ans = 1;

    for(long long a = 0; a <= min(d[0] - 1, k); ++a){
        long long rem = k - a;

        // Try a few candidate b values
        vector<long long> cand;

        // edge candidates
        cand.push_back(0);
        cand.push_back(min(d[1] - 1, rem));

        // balanced candidate around rem/2
        long long bmid = rem / 2;
        cand.push_back(min(d[1] - 1, bmid));
        cand.push_back(min(d[1] - 1, bmid + 1));

        // candidate that makes c = max
        long long b_for_max_c = max(0LL, rem - (d[2] - 1));
        cand.push_back(min(d[1] - 1, b_for_max_c));
        cand.push_back(min(d[1] - 1, b_for_max_c + 1));

        for(long long b : cand){
            if(b < 0) continue;
            if(b > d[1] - 1) continue;
            if(b > rem) continue;

            long long c = min(d[2] - 1, rem - b);

            if(c < 0) continue;

            long long pieces = (a + 1) * (b + 1) * (c + 1);
            ans = max(ans, pieces);
        }
    }

    cout << ans << "\n";
    return 0;
}
