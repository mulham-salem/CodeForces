#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
    long long val;
    int group_id;
    int scientist_id;

    bool operator<(const Problem& other) const {
        if (group_id != other.group_id) {
            return group_id < other.group_id;
        }
        if (val != other.val) {
            return val < other.val;
        }
        return scientist_id < other.scientist_id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Problem> all_problems;
    long long total_problems = 0;

    for (int i = 1; i <= n; ++i) {
        long long k, a1, x, y, m;
        cin >> k >> a1 >> x >> y >> m;

        total_problems += k;

        long long current_val = a1;
        int group = 0;

        all_problems.push_back({current_val, group, i});

        for (int j = 2; j <= k; ++j) {
            long long next_val = (current_val * x + y) % m;

            if (next_val < current_val) {
                group++;
            }

            all_problems.push_back({next_val, group, i});
            current_val = next_val;
        }
    }

    sort(all_problems.begin(), all_problems.end());

    int bad_pairs = 0;
    for (size_t i = 1; i < all_problems.size(); ++i) {
        if (all_problems[i].val < all_problems[i - 1].val) {
            bad_pairs++;
        }
    }

    cout << bad_pairs << "\n";

    if (total_problems <= 200000) {
        for (const auto& prob : all_problems) {
            cout << prob.val << " " << prob.scientist_id << "\n";
        }
    }

    return 0;
}
