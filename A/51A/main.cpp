#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> st;

    while (n--) {
        string a, b;
        cin >> a >> b;

        vector<string> v;

        v.push_back(a + b);                           // original
        v.push_back(string() + b[0] + a[0] + b[1] + a[1]); // 90
        v.push_back(string() + b[1] + b[0] + a[1] + a[0]); // 180
        v.push_back(string() + a[1] + b[1] + a[0] + b[0]); // 270

        sort(v.begin(), v.end());
        st.insert(v[0]);

        if (n) {
            string tmp;
            cin >> tmp;
        }
    }

    cout << st.size();

    return 0;
}
