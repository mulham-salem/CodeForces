#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> pre(n + 1, 0);
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] + (s[i] == '[');

    vector<int> dp(n, 0);
    stack<int> st;

    int bestCnt = 0;
    int bestL = -1, bestR = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '[') {
            st.push(i);
        } else {
            if (!st.empty()) {
                int j = st.top();

                if ((s[j] == '(' && s[i] == ')') ||
                    (s[j] == '[' && s[i] == ']')) {

                    st.pop();

                    dp[i] = i - j + 1;
                    if (j > 0)
                        dp[i] += dp[j - 1];

                    int L = i - dp[i] + 1;
                    int cnt = pre[i + 1] - pre[L];

                    if (cnt > bestCnt) {
                        bestCnt = cnt;
                        bestL = L;
                        bestR = i;
                    }
                } else {
                    while (!st.empty())
                        st.pop();
                }
            }
        }
    }

    cout << bestCnt << "\n";
    if (bestL != -1)
        cout << s.substr(bestL, bestR - bestL + 1);
    cout << "\n";

    return 0;
}
