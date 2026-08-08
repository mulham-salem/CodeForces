#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int INF = 1e9;

    // cost[col] = minimum shifts needed for the current row
    // to put a '1' at column col.
    vector<int> cost(m);

    // answer[col] = total minimum shifts for all rows
    // to make column col contain only 1s.
    vector<int> answer(m, 0);

    for (int i = 0; i < n; i++) {

        fill(cost.begin(), cost.end(), INF);

        // Put 0 at every position containing '1'.
        // Then calculate distance to the nearest 1
        // in both directions.
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                cost[j] = 0;
            }
        }

        // Left -> Right
        for (int j = 1; j < m; j++) {
            cost[j] = min(cost[j], cost[j - 1] + 1);
        }

        // Right -> Left
        for (int j = m - 2; j >= 0; j--) {
            cost[j] = min(cost[j], cost[j + 1] + 1);
        }

        // Calculate exact cyclic distance using the nearest 1
        // from the left and right ends.
        int firstOne = -1;
        int lastOne = -1;

        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                if (firstOne == -1)
                    firstOne = j;

                lastOne = j;
            }
        }

        if (firstOne == -1) {
            // This row has no '1', so no column can ever
            // become all ones.
            cout << -1 << '\n';
            return 0;
        }

        // Handle circular wrap-around.
        for (int col = 0; col < m; col++) {
            int wrapDistance = min(
                col + m - lastOne,
                firstOne + m - col
            );

            cost[col] = min(cost[col], wrapDistance);
        }

        // Add this row's cost to every target column.
        for (int col = 0; col < m; col++) {
            answer[col] += cost[col];
        }
    }

    cout << *min_element(answer.begin(), answer.end()) << '\n';

    return 0;
}
